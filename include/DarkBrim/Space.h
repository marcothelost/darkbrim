#ifndef DKB_SPACE_H
#define DKB_SPACE_H

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

#endif // DKB_SPACE_H
