#include "DarkBrim/Core.h"

/**
 * @brief Prints information about the DarkBrim engine.
 */
void dkb_printEngineInfo()
{
  printf("%s %s\n", DKB_ENGINE_NAME, DKB_ENGINE_VERSION);
  printf("Created by %s\n", DKB_ENGINE_AUTHOR);
  printf("Licensed under %s\n", DKB_ENGINE_LICENSE);
}

/**
 * @brief Prints version information about OpenGL, GLEW, and GLFW.
 */
void dkb_printVersionInfo()
{
  printf("OpenGL: %s\n", glGetString(GL_VERSION));
  printf("GLEW:   %s\n", glewGetString(GLEW_VERSION));
  printf("GLFW:   %s\n", glfwGetVersionString());
}
