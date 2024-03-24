#include "DarkBrim/Graphics.h"

void dkb_usePointMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); }
void dkb_useLineMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
void dkb_useFillMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

void dkb_initShader(dkb_Shader* shader, const char* vertexPath, const char* fragmentPath)
{
  // Shader Sources
  const char* vertexShaderSource = dkb_getFileContents(vertexPath);
  const char* fragmentShaderSource = dkb_getFileContents(fragmentPath);

  // Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // Info Log
  int success = 0;
  char infoLog[DKB_INFO_LOG_SIZE];

  // Validating the Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, DKB_INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to compile the vertex shader!\n");
    fprintf(stderr, "Error: \n%s\n", infoLog);
  }

  // Validating the Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, DKB_INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to compile the fragment shader!\n");
    fprintf(stderr, "Error: \n%s\n", infoLog);
  }

  // Shader Program
  shader->ID = glCreateProgram();
  glAttachShader(shader->ID, vertexShader);
  glAttachShader(shader->ID, fragmentShader);
  glLinkProgram(shader->ID);

  // Validating the Shader Program
  glGetProgramiv(fragmentShader, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, DKB_INFO_LOG_SIZE, NULL, infoLog);
    fprintf(stderr, "Failed to link the shader program!\n");
    fprintf(stderr, "Error: \n%s\n", infoLog);
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}
void dkb_useShader(dkb_Shader* shader)
{ glUseProgram(shader->ID); }
void dkb_deleteShader(dkb_Shader* shader)
{ glDeleteProgram(shader->ID); }
void dkb_shader_setMat4(dkb_Shader* shader, const char* uniform, dkb_Mat4* mat)
{
  GLuint matLoc = glGetUniformLocation(shader->ID, uniform);
  glUniformMatrix4fv(matLoc, 1, GL_FALSE, dkb_valuePointer_mat4(mat));
}

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

void dkb_initVAO(dkb_VAO* VAO)
{ glGenVertexArrays(1, &VAO->ID); }
void dkb_bindVAO(dkb_VAO* VAO)
{ glBindVertexArray(VAO->ID); }
void dkb_unbindVAO()
{ glBindVertexArray(0); }
void dkb_deleteVAO(dkb_VAO* VAO)
{ glDeleteVertexArrays(1, &VAO->ID); }
void dkb_linkAttribute(dkb_VBO* VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset)
{
  dkb_bindVBO(VBO);
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  dkb_unbindVBO(VBO);
}
