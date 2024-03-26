#ifndef DKB_CAMERA_H
#define DKB_CAMERA_H

#include <math.h>
#include <stdio.h>

#include "Keys.h"
#include "Graphics.h"
#include "Window.h"
#include "Space.h"
#include "Debug.h"

/**
 * @brief Represents a camera in DarkBrim.
 */
typedef struct dkb_Camera
{
  float fov;
  float aspect;
  float zNear;
  float zFar;
  float speed;
  float sensitivity;
  dkb_Vec3 position;
  dkb_Vec3 front;
  dkb_Vec3 up;
  dkb_Mat4 matrix;
  float yaw;
  float pitch;
} dkb_Camera;

/**
 * @brief Initializes a camera with the specified parameters.
 * 
 * @param camera Pointer to the dkb_Camera structure representing the camera to be initialized.
 * @param fov The field of view angle of the camera (in degrees).
 * @param aspect The aspect ratio of the camera.
 * @param zNear The distance to the near clipping plane of the camera.
 * @param zFar The distance to the far clipping plane of the camera.
 * @param speed The movement speed of the camera.
 * @param sensitivity The sensitivity of the camera's controls.
 */
void dkb_initCamera(dkb_Camera* camera, const float fov, const float aspect, const float zNear, const float zFar, const float speed, const float sensitivity);
/**
 * @brief Handles camera movement based on user input.
 * 
 * @param window Pointer to the dkb_Window structure representing the window.
 * @param camera Pointer to the dkb_Camera structure representing the camera.
 */
void dkb_handleCameraMovement(dkb_Window* window, dkb_Camera* camera);
/**
 * @brief Updates the camera's transformation matrix.
 * 
 * @param camera Pointer to the dkb_Camera structure representing the camera.
 */
void dkb_updateCameraMatrix(dkb_Camera* camera);
/**
 * @brief Applies the camera's transformation matrix to a shader program.
 * 
 * @param camera Pointer to the dkb_Camera structure representing the camera.
 * @param shader Pointer to the dkb_Shader structure representing the shader program.
 * @param uniform Name of the uniform variable in the shader program where the camera matrix will be applied.
 */
void dkb_applyCameraMatrix(dkb_Camera* camera, dkb_Shader* shader, const char* uniform);

#endif // DKB_CAMERA_H
