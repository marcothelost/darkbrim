#ifndef DKB_GRAPHICS_H
#define DKB_GRAPHICS_H

#include <GL/glew.h>

/**
 * @brief Sets the polygon rendering mode to point mode.
 */
static void dkb_usePointMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); }
/**
 * @brief Sets the polygon rendering mode to line mode.
 */
static void dkb_useLineMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
/**
 * @brief Sets the polygon rendering mode to fill mode.
 */
static void dkb_useFillMode()
{ glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

#endif // DKB_GRAPHICS_H
