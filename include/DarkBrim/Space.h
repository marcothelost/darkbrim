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
 * @brief Creates a 3-dimensional vector with the specified components.
 * 
 * @param x The x-component of the vector.
 * @param y The y-component of the vector.
 * @param z The z-component of the vector.
 * @return A new dkb_Vec3 structure representing the created vector.
 */
dkb_Vec3 dkb_vec3(const float x, const float y, const float z);

#endif // DKB_SPACE_H
