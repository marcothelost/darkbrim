#ifndef DKB_CAMERA_H
#define DKB_CAMERA_H

#include "Space.h"

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
  dkb_Vec3 position;
  dkb_Mat4 matrix;
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
 */
void dkb_initCamera(dkb_Camera* camera, const float fov, const float aspect, const float zNear, const float zFar, const float speed);

#endif // DKB_CAMERA_H
