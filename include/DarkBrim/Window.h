#ifndef DKB_WINDOW_H
#define DKB_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Structure representing a window in the DarkBrim engine.
 */
typedef struct dkb_Window
{
  GLFWwindow* glfwInstance;
  char* title;
  unsigned int window;
  unsigned int height;
  float aspect;
  float lastTime;
  float deltaTime;
  bool mouseLocked;
} dkb_Window;

/**
 * @brief Initializes a window with the specified title, width, and height.
 * 
 * @param window Pointer to the dkb_Window structure to be initialized.
 * @param title Title of the window.
 * @param width Width of the window.
 * @param height Height of the window.
 */
void dkb_initWindow(dkb_Window* window, const char* title, const unsigned int width, const unsigned int height);
/**
 * @brief Updates the window.
 * 
 * @param window Pointer to the dkb_Window structure representing the window to be updated.
 */
void dkb_updateWindow(dkb_Window* window);
/**
 * @brief Makes a window the current OpenGL context.
 * 
 * @param window Pointer to the dkb_Window structure representing the window to be used.
 */
void dkb_useWindow(dkb_Window* window);

/**
 * @brief Locks the mouse cursor within the window's boundaries.
 * 
 * @param window Pointer to the dkb_Window structure representing the window.
 */
void dkb_lockMouse(dkb_Window* window);
/**
 * @brief Unlocks the mouse cursor, allowing it to move freely.
 * 
 * @param window Pointer to the dkb_Window structure representing the window.
 */
void dkb_unlockMouse(dkb_Window* window);

#endif // DKB_WINDOW_H
