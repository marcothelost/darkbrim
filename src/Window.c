#include "DarkBrim/Window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void dkb_initWindow(dkb_Window* window, const char* title, const unsigned int width, const unsigned int height)
{
  window->glfwInstance = glfwCreateWindow(
    width,
    height,
    title,
    NULL,
    NULL
  );
  if (window == NULL)
  {
    fprintf(stderr, "Failed to create a GLFW window!\n");
  }
  glfwSetFramebufferSizeCallback(window->glfwInstance, framebufferSizeCallback);
}
void dkb_useWindow(dkb_Window* window)
{
  glfwMakeContextCurrent(window->glfwInstance);
}
