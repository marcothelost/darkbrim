#ifndef DKB_GRAPHICS_H
#define DKB_GRAPHICS_H

#include <GL/glew.h>

/**
 * @brief Sets the polygon rendering mode to point mode.
 */
void dkb_usePointMode();
/**
 * @brief Sets the polygon rendering mode to line mode.
 */
void dkb_useLineMode();
/**
 * @brief Sets the polygon rendering mode to fill mode.
 */
void dkb_useFillMode();

/**
 * @brief Structure representing a Vertex Buffer Object (VBO).
 */
typedef struct dkb_VBO
{
  GLuint ID;
  GLfloat* vertices;
  GLuint* indices;
} dkb_VBO;

/**
 * @brief Initializes a Vertex Buffer Object (VBO) with given vertices data.
 * 
 * @param VBO Pointer to the VBO structure to be initialized.
 * @param vertices Pointer to the vertices data.
 * @param verticesSize Size of the vertices data in bytes.
 */
void dkb_initVBO(dkb_VBO* VBO, GLfloat* vertices, GLsizeiptr verticesSize);
/**
 * @brief Binds a Vertex Buffer Object (VBO) for use.
 * 
 * @param VBO Pointer to the VBO structure to be bound.
 */
void dkb_bindVBO(dkb_VBO* VBO);
/**
 * @brief Unbinds the currently bound Vertex Buffer Object (VBO).
 */
void dkb_unbindVBO();
/**
 * @brief Deletes a Vertex Buffer Object (VBO) and frees its resources.
 * 
 * @param VBO Pointer to the VBO structure to be deleted.
 */
void dkb_deleteVBO(dkb_VBO* VBO);

#endif // DKB_GRAPHICS_H
