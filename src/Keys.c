#include "DarkBrim/Keys.h"

bool dkb_isKeyPressed(GLFWwindow* window, enum dkb_Key key)
{
  return glfwGetKey(window, key) == GLFW_PRESS;
}
