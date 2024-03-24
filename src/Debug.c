#include "DarkBrim/Debug.h"

void dkb_printVec3(dkb_Vec3* vec)
{
  printf("X: %.2f; Y: %.2f; Z: %.2f\n", vec->x, vec->y, vec->z);
}

void dkb_printMat4(dkb_Mat4* mat)
{
  for (int y = 0; y < 4; y++)
  {
    for (int x = 0; x < 4; x++)
    {
      printf("%.2f ", mat->elements[y][x]);
    }
    printf("\n");
  }
}
