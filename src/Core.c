#include "DarkBrim/Core.h"

void dkb_initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
}

void dkb_initialize()
{
  glPointSize(DKB_DEFAULT_RENDER_SETTINGS.pointSize);
  glLineWidth(DKB_DEFAULT_RENDER_SETTINGS.lineWidth);
}

void dkb_printEngineInfo()
{
  printf("%s %s\n", DKB_ENGINE_NAME, DKB_ENGINE_VERSION);
  printf("Created by %s\n", DKB_ENGINE_AUTHOR);
  printf("Licensed under %s\n", DKB_ENGINE_LICENSE);
}

void dkb_printVersionInfo()
{
  printf("OpenGL: %s\n", glGetString(GL_VERSION));
  printf("GLEW:   %s\n", glewGetString(GLEW_VERSION));
  printf("GLFW:   %s\n", glfwGetVersionString());
}
