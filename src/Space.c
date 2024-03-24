#include "DarkBrim/Space.h"

float dkb_radians(const float degrees)
{
  return degrees * DKB_PI / 180.f;
}

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

dkb_Mat4 dkb_add_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo)
{
  dkb_Mat4 result;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      result.elements[y][x] = matOne->elements[y][x] + matTwo->elements[y][x];
    }
  }
  return result;
}

dkb_Mat4 dkb_sub_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo)
{
  dkb_Mat4 result;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      result.elements[y][x] = matOne->elements[y][x] - matTwo->elements[y][x];
    }
  }
  return result;
}

dkb_Mat4 dkb_mult_mat4_int(dkb_Mat4* mat, const int scalar)
{
  dkb_Mat4 result = *mat;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      result.elements[y][x] * scalar;
    }
  }
  return result;
}

dkb_Mat4 dkb_mult_mat4_float(dkb_Mat4* mat, const float scalar)
{
  dkb_Mat4 result = *mat;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      result.elements[y][x] * scalar;
    }
  }
  return result;
}

dkb_Mat4 dkb_mult_mat4_double(dkb_Mat4* mat, const double scalar)
{
  dkb_Mat4 result = *mat;
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      result.elements[y][x] * scalar;
    }
  }
  return result;
}

dkb_Mat4 dkb_mult_mat4_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo)
{
  dkb_Mat4 result;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      result.elements[i][j] = 0.f;
      for (int k = 0; k < 4; k++)
      {
        result.elements[i][j] += matOne->elements[i][k] * matTwo->elements[k][j];
      }
    }
  }
  return result;
}

float* dkb_valuePointer_mat4(dkb_Mat4* mat)
{
  return &mat->elements[0][0];
}

dkb_Mat4 dkb_translate_mat4(dkb_Mat4* mat, dkb_Vec3* vec)
{
  dkb_Mat4 result = *mat;
  result.elements[3][0] = vec->x;
  result.elements[3][1] = vec->y;
  result.elements[3][2] = vec->z;
  return result;
}

dkb_Mat4 dkb_projection_mat4(const float fov, const float aspect, const float zNear, const float zFar)
{
  const float halfTanFOV = tanf(dkb_radians(fov)) / 2.f;
  dkb_Mat4 result = dkb_mat4(0.f);

  result.elements[0][0] = 1.f / (aspect * halfTanFOV);
  result.elements[1][1] = 1.f / halfTanFOV;
  result.elements[2][2] = (zFar + zNear) / (zNear - zFar);
  result.elements[2][3] = -1.f;
  result.elements[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

  return result;
}
