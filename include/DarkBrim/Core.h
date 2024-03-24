#ifndef DKB_CORE_H
#define DKB_CORE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Constants.h"

/**
 * @brief Initializes GLFW library for DarkBrim engine usage.
 */
void dkb_initializeGlfw();
/**
 * @brief Initializes the DarkBrim engine.
 */
void dkb_initialize();
/**
 * @brief Prints information about the DarkBrim engine.
 */
void dkb_printVersionInfo();
/**
 * @brief Prints version information about OpenGL, GLEW, and GLFW.
 */
void dkb_printEngineInfo();

#endif // DKB_CORE_H
