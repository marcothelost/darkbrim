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

void dkb_initEBO(dkb_EBO* EBO, GLuint* indices, GLsizeiptr indicesSize)
{
  glGenBuffers(1, &EBO->ID);
  dkb_bindEBO(EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
  dkb_unbindEBO(EBO);
}
void dkb_bindEBO(dkb_EBO* EBO)
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO->ID); }
void dkb_unbindEBO()
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
void dkb_deleteEBO(dkb_EBO* EBO)
{ glDeleteBuffers(1, &EBO->ID); }
