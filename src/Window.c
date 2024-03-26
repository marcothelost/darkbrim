#include "DarkBrim/Window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  dkb_Window* windowInstance = (dkb_Window*)glfwGetWindowUserPointer(window);
  windowInstance->aspect = (float)width / height;

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
  glfwSetWindowUserPointer(window->glfwInstance, window);

  window->aspect = (float)width / height;
  window->lastTime = (float)glfwGetTime();
  window->mouseLocked = false;
}

void dkb_updateWindow(dkb_Window* window)
{
  float currentTime = (float)glfwGetTime();
  window->deltaTime = currentTime - window->lastTime;
  window->lastTime  = currentTime;
}

void dkb_useWindow(dkb_Window* window)
{
  glfwMakeContextCurrent(window->glfwInstance);
}

void dkb_lockMouse(dkb_Window* window)
{
  window->mouseLocked = true;
  glfwSetInputMode(window->glfwInstance, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void dkb_unlockMouse(dkb_Window* window)
{
  window->mouseLocked = false;
  glfwSetInputMode(window->glfwInstance, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
