#ifndef DKB_SPACE_H
#define DKB_SPACE_H

#include <math.h>

/**
 * @brief A constant representing the value of pi (π).
 */
static const float DKB_PI = 3.141593f;
/**
 * @brief Converts degrees to radians.
 * 
 * @param degrees The angle in degrees to be converted.
 * @return The equivalent angle in radians.
 */
float dkb_radians(const float degrees);

/**
 * @brief Structure representing a 3-dimensional vector.
 */
typedef struct dkb_Vec3
{
  float x;
  float y;
  float z;
} dkb_Vec3;

/**
 * @brief Structure representing a 4x4 matrix.
 */
typedef struct dkb_Mat4
{
  float elements[4][4];
} dkb_Mat4;

/**
 * @brief Creates a 3-dimensional vector with the specified components.
 * 
 * @param x The x-component of the vector.
 * @param y The y-component of the vector.
 * @param z The z-component of the vector.
 * @return A new dkb_Vec3 structure representing the created vector.
 */
dkb_Vec3 dkb_vec3(const float x, const float y, const float z);

/**
 * @brief Normalizes a 3-dimensional vector.
 * 
 * @param vec Pointer to the dkb_Vec3 structure representing the vector to be normalized.
 * @return A new dkb_Vec3 structure representing the normalized vector.
 */
dkb_Vec3 dkb_normalize_vec3(dkb_Vec3* vec);

/**
 * @brief Adds two 3-dimensional vectors component-wise.
 * 
 * @param vecOne Pointer to the first vector.
 * @param vecTwo Pointer to the second vector.
 * @return A new dkb_Vec3 structure representing the result of the addition.
 */
dkb_Vec3 dkb_add_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo);
/**
 * @brief Subtracts two 3-dimensional vectors component-wise.
 * 
 * @param vecOne Pointer to the first vector.
 * @param vecTwo Pointer to the second vector.
 * @return A new dkb_Vec3 structure representing the result of the subtraction.
 */
dkb_Vec3 dkb_sub_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo);
/**
 * @brief Multiplies a 3-dimensional vector by an integer scalar.
 * 
 * @param vec Pointer to the vector.
 * @param scalar The integer scalar.
 * @return A new dkb_Vec3 structure representing the result of the multiplication.
 */
dkb_Vec3 dkb_mult_vec3_int(dkb_Vec3* vec, const int scalar);
/**
 * @brief Multiplies a 3-dimensional vector by a float scalar.
 * 
 * @param vec Pointer to the vector.
 * @param scalar The float scalar.
 * @return A new dkb_Vec3 structure representing the result of the multiplication.
 */
dkb_Vec3 dkb_mult_vec3_float(dkb_Vec3* vec, const float scalar);
/**
 * @brief Multiplies a 3-dimensional vector by a double scalar.
 * 
 * @param vec Pointer to the vector.
 * @param scalar The double scalar.
 * @return A new dkb_Vec3 structure representing the result of the multiplication.
 */
dkb_Vec3 dkb_mult_vec3_double(dkb_Vec3* vec, const double scalar);

/**
 * @brief Calculates the dot product of two 3-dimensional vectors.
 * 
 * @param vecOne Pointer to the first vector.
 * @param vecTwo Pointer to the second vector.
 * @return The dot product of the two vectors.
 */
float dkb_dot_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo);
/**
 * @brief Calculates the cross product of two 3-dimensional vectors.
 * 
 * @param vecOne Pointer to the first vector.
 * @param vecTwo Pointer to the second vector.
 * @return A new dkb_Vec3 structure representing the cross product of the two vectors.
 */
dkb_Vec3 dkb_cross_vec3(dkb_Vec3* vecOne, dkb_Vec3* vecTwo);

/**
 * @brief Creates a 4x4 matrix with the specified diagonal value.
 * 
 * @param diagonalValue The value to be set on the diagonal of the matrix.
 * @return A new dkb_Mat4 structure representing the created matrix.
 */
dkb_Mat4 dkb_mat4(const float diagonalValue);

/**
 * @brief Adds two 4x4 matrices element-wise.
 * 
 * @param matOne Pointer to the first matrix.
 * @param matTwo Pointer to the second matrix.
 * @return A new dkb_Mat4 structure representing the result of the addition.
 */
dkb_Mat4 dkb_add_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo);
/**
 * @brief Subtracts two 4x4 matrices element-wise.
 * 
 * @param matOne Pointer to the first matrix.
 * @param matTwo Pointer to the second matrix.
 * @return A new dkb_Mat4 structure representing the result of the subtraction.
 */
dkb_Mat4 dkb_sub_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo);
/**
 * @brief Multiplies a 4x4 matrix by an integer scalar.
 * 
 * @param mat Pointer to the matrix.
 * @param scalar The integer scalar.
 * @return A new dkb_Mat4 structure representing the result of the multiplication.
 */
dkb_Mat4 dkb_mult_mat4_int(dkb_Mat4* mat, const int scalar);
/**
 * @brief Multiplies a 4x4 matrix by a float scalar.
 * 
 * @param mat Pointer to the matrix.
 * @param scalar The float scalar.
 * @return A new dkb_Mat4 structure representing the result of the multiplication.
 */
dkb_Mat4 dkb_mult_mat4_float(dkb_Mat4* mat, const float scalar);
/**
 * @brief Multiplies a 4x4 matrix by a double scalar.
 * 
 * @param mat Pointer to the matrix.
 * @param scalar The double scalar.
 * @return A new dkb_Mat4 structure representing the result of the multiplication.
 */
dkb_Mat4 dkb_mult_mat4_double(dkb_Mat4* mat, const double scalar);
/**
 * @brief Multiplies two 4x4 matrices.
 * 
 * @param matOne Pointer to the first matrix.
 * @param matTwo Pointer to the second matrix.
 * @return A new dkb_Mat4 structure representing the result of the multiplication.
 */
dkb_Mat4 dkb_mult_mat4_mat4(dkb_Mat4* matOne, dkb_Mat4* matTwo);

/**
 * @brief Retrieves a pointer to the elements of a 4x4 matrix.
 * 
 * @param mat Pointer to the dkb_Mat4 structure representing the matrix.
 * @return A pointer to the elements of the matrix.
 */
float* dkb_valuePointer_mat4(dkb_Mat4* mat);
/**
 * @brief Applies a translation to a 4x4 matrix.
 * 
 * @param mat Pointer to the dkb_Mat4 structure representing the input matrix.
 * @param vec Pointer to the dkb_Vec3 structure representing the translation vector.
 * @return A new dkb_Mat4 structure representing the resulting matrix after translation.
 */
dkb_Mat4 dkb_translate_mat4(dkb_Mat4* mat, dkb_Vec3* vec);
/**
 * @brief Generates a perspective projection matrix.
 * 
 * @param fov The field of view angle (in degrees).
 * @param aspect The aspect ratio (width/height) of the viewport.
 * @param zNear The distance to the near clipping plane.
 * @param zFar The distance to the far clipping plane.
 * @return A dkb_Mat4 structure representing the generated perspective projection matrix.
 */
dkb_Mat4 dkb_projection_mat4(const float fov, const float aspect, const float zNear, const float zFar);
/**
 * @brief Creates a view matrix for a camera positioned at the specified eye point,
 * looking toward the target point, with the specified up direction.
 * 
 * @param eye Pointer to the dkb_Vec3 structure representing the eye position.
 * @param target Pointer to the dkb_Vec3 structure representing the target position.
 * @param up Pointer to the dkb_Vec3 structure representing the up direction.
 * @return A new dkb_Mat4 structure representing the view matrix.
 */
dkb_Mat4 dkb_lookAt_mat4(dkb_Vec3* eye, dkb_Vec3* target, dkb_Vec3* up);

#endif // DKB_SPACE_H
