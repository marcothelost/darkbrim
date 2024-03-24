#include "DarkBrim/Space.h"

dkb_Vec3 dkb_vec3(const float x, const float y, const float z)
{
  dkb_Vec3 vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

dkb_Vec3 dkb_add_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo)
{
  dkb_Vec3 result =
  {
    .x = vecOne->x + vecTwo->x,
    .y = vecOne->y + vecTwo->y,
    .z = vecOne->z + vecTwo->z
  };
  return result;
}

dkb_Vec3 dkb_sub_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo)
{
  dkb_Vec3 result =
  {
    .x = vecOne->x - vecTwo->x,
    .y = vecOne->y - vecTwo->y,
    .z = vecOne->z - vecTwo->z
  };
  return result;
}

dkb_Vec3 dkb_mult_vec3_int(dkb_Vec3* vec, const int scalar)
{
  dkb_Vec3 result =
  {
    .x = vec->x * scalar,
    .y = vec->y * scalar,
    .z = vec->z * scalar
  };
  return result;
}

dkb_Vec3 dkb_mult_vec3_float(dkb_Vec3* vec, const float scalar)
{
  dkb_Vec3 result =
  {
    .x = vec->x * scalar,
    .y = vec->y * scalar,
    .z = vec->z * scalar
  };
  return result;
}

dkb_Vec3 dkb_mult_vec3_double(dkb_Vec3* vec, const double scalar)
{
  dkb_Vec3 result =
  {
    .x = vec->x * scalar,
    .y = vec->y * scalar,
    .z = vec->z * scalar
  };
  return result;
}

float dkb_dot_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo)
{
  return vecOne->x * vecTwo->x + vecOne->y * vecTwo->y + vecOne->z * vecTwo->z;
}

dkb_Vec3 dkb_cross_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo)
{
  dkb_Vec3 result =
  {
    .x = vecOne->y * vecTwo->z - vecOne->z * vecTwo->y,
    .y = vecOne->z * vecTwo->x - vecOne->x * vecTwo->z,
    .z = vecOne->x * vecTwo->y - vecOne->y * vecTwo->x
  };
  return result;
}

dkb_Mat4 dkb_mat4(const float diagonalValue)
{
  dkb_Mat4 mat;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      mat.elements[y][x] = x == y ? diagonalValue : 0.f;
    }
  }
  return mat;
}
