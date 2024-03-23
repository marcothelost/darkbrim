#include "DarkBrim/Graphics.h"

void dkb_usePointMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); }
void dkb_useLineMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
void dkb_useFillMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

void dkb_initVBO(dkb_VBO* VBO, GLfloat* vertices, GLsizeiptr verticesSize)
{
  glGenBuffers(1, &VBO->ID);
  dkb_bindVBO(VBO);
  glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
  dkb_unbindVBO(VBO);
}
void dkb_bindVBO(dkb_VBO* VBO)
{ glBindBuffer(GL_ARRAY_BUFFER, VBO->ID); }
void dkb_unbindVBO()
{ glBindBuffer(GL_ARRAY_BUFFER, 0); }
void dkb_deleteVBO(dkb_VBO* VBO)
{ glDeleteBuffers(1, &VBO->ID); }
