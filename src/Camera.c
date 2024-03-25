#include "DarkBrim/Camera.h"

void dkb_initCamera(dkb_Camera* camera, const float fov, const float aspect, const float zNear, const float zFar, const float speed)
{
  camera->position = dkb_vec3(0.f, 0.f, -3.f);
  camera->fov = fov;
  camera->aspect = aspect;
  camera->zNear = zNear;
  camera->zFar = zFar;
  camera->speed = speed;
}
