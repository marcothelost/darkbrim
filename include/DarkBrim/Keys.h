#ifndef DKB_KEYS_H
#define DKB_KEYS_H

#include <GLFW/glfw3.h>
#include <stdbool.h>

/**
 * @brief Enumeration of keys used in DarkBrim.
 */
enum dkb_Key
{
  W = GLFW_KEY_W,
  S = GLFW_KEY_S,
};

/**
 * @brief Checks if a specific key is pressed.
 * 
 * @param window Pointer to the GLFWwindow instance.
 * @param key The key to check.
 * @return true if the key is pressed, false otherwise.
 */
bool dkb_isKeyPressed(GLFWwindow* window, enum dkb_Key key);

#endif // DKB_KEYS_H
