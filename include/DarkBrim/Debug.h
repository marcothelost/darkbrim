#ifndef DKB_DEBUG_H
#define DKB_DEBUG_H

#include <stdio.h>

#include "Space.h"

/**
 * @brief Prints the components of a 3-dimensional vector.
 * 
 * @param vec Pointer to the dkb_Vec3 structure representing the vector to be printed.
 */
void dkb_printVec3(dkb_Vec3* vec);
/**
 * @brief Prints the elements of a 4x4 matrix.
 * 
 * @param mat Pointer to the dkb_Mat4 structure representing the matrix to be printed.
 */
void dkb_printMat4(dkb_Mat4* mat);

#endif // DKB_DEBUG_H
