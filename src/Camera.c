#include "DarkBrim/Camera.h"

void dkb_initCamera(dkb_Camera* camera, const float fov, const float aspect, const float zNear, const float zFar, const float speed, const float sensitivity)
{
  camera->position = dkb_vec3(0.f, 0.f, -3.f);
  camera->front = dkb_vec3(0.f, 0.f, -1.f);
  camera->up = dkb_vec3(0.f, 1.f, 0.f);
  camera->matrix = dkb_mat4(0.f);
  camera->fov = fov;
  camera->aspect = aspect;
  camera->zNear = zNear;
  camera->zFar = zFar;
  camera->speed = speed;
  camera->sensitivity = sensitivity;
  camera->yaw = 90.f;
  camera->pitch = 0.f;
}

void dkb_handleCameraMovement(dkb_Window* window, dkb_Camera* camera)
{
  if (!window->mouseLocked) return;

  if (dkb_isKeyPressed(window->glfwInstance, W))
  {
    dkb_Vec3 factor = dkb_mult_vec3_float(&camera->front, camera->speed * window->deltaTime);
    camera->position = dkb_add_vec3(&camera->position, &factor);
  }
  if (dkb_isKeyPressed(window->glfwInstance, S))
  {
    dkb_Vec3 factor = dkb_mult_vec3_float(&camera->front, camera->speed * window->deltaTime);
    camera->position = dkb_sub_vec3(&camera->position, &factor);
  }
  if (dkb_isKeyPressed(window->glfwInstance, A))
  {
    dkb_Vec3 direction = dkb_cross_vec3(&camera->front, &camera->up);
    dkb_Vec3 factor = dkb_mult_vec3_float(&direction, camera->speed * window->deltaTime);
    camera->position = dkb_sub_vec3(&camera->position, &factor);
  }
  if (dkb_isKeyPressed(window->glfwInstance, D))
  {
    dkb_Vec3 direction = dkb_cross_vec3(&camera->front, &camera->up);
    dkb_Vec3 factor = dkb_mult_vec3_float(&direction, camera->speed * window->deltaTime);
    camera->position = dkb_add_vec3(&camera->position, &factor);
  }

  if (dkb_isKeyPressed(window->glfwInstance, Spacebar))
  {
    dkb_Vec3 factor = dkb_mult_vec3_float(&camera->up, camera->speed * window->deltaTime);
    camera->position = dkb_add_vec3(&camera->position, &factor);
  }
  if (dkb_isKeyPressed(window->glfwInstance, LeftShift))
  {
    dkb_Vec3 factor = dkb_mult_vec3_float(&camera->up, camera->speed * window->deltaTime);
    camera->position = dkb_sub_vec3(&camera->position, &factor);
  }

  double mouseX;
  double mouseY;
  glfwGetCursorPos(window->glfwInstance, &mouseX, &mouseY);

  int bufferWidth;
  int bufferHeight;
  glfwGetFramebufferSize(window->glfwInstance, &bufferWidth, &bufferHeight);

  float deltaX = (mouseX - (float)bufferWidth / 2.f) * camera->sensitivity;
  float deltaY = (mouseY - (float)bufferHeight / 2.f) * camera->sensitivity;

  camera->yaw += deltaX;
  camera->pitch -= deltaY;

  if (camera->pitch > 179.f) camera->pitch = 179.f;
  if (camera->pitch < -179.f) camera->pitch = -179.f;
  camera->yaw = fmod(camera->yaw, 360.f);

  glfwSetCursorPos(window->glfwInstance, (float)bufferWidth / 2.f,(float)bufferHeight / 2.f);
}

void dkb_updateCameraMatrix(dkb_Camera* camera)
{
  dkb_Mat4 view = dkb_mat4(1.f);
  dkb_Mat4 proj = dkb_mat4(1.f);
  dkb_Vec3 tempFront = dkb_vec3(0.f, 0.f, 0.f);

  tempFront.x = cosf(dkb_radians(camera->yaw)) * cosf(dkb_radians(camera->pitch));
  tempFront.y = sinf(dkb_radians(camera->pitch));
  tempFront.z = sinf(dkb_radians(camera->yaw)) * cosf(dkb_radians(camera->pitch));

  camera->front = dkb_normalize_vec3(&tempFront);
  
  dkb_Vec3 cameraTarget = dkb_add_vec3(&camera->position, &camera->front);

  view = dkb_lookAt_mat4(&camera->position, &cameraTarget, &camera->up);
  proj = dkb_projection_mat4(
    camera->fov,
    camera->aspect,
    camera->zNear,
    camera->zFar
  );

  camera->matrix = dkb_mult_mat4_mat4(&view, &proj);
}

void dkb_applyCameraMatrix(dkb_Camera* camera, dkb_Shader* shader, const char* uniform)
{
  dkb_shader_setMat4(shader, uniform, &camera->matrix);
}
