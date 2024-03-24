#ifndef DKB_GRAPHICS_H
#define DKB_GRAPHICS_H

#include <GL/glew.h>

#include "Constants.h"

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
 * @brief Structure representing a shader in the DarkBrim engine.
 */
typedef struct dkb_Shader
{
  GLuint ID;
} dkb_Shader;

/**
 * @brief Structure representing a Vertex Buffer Object (VBO).
 */
typedef struct dkb_VBO
{
  GLuint ID;
} dkb_VBO;

/**
 * @brief Structure representing an Element Buffer Object (EBO).
 */
typedef struct dkb_EBO
{
  GLuint ID;
} dkb_EBO;

/**
 * @brief Structure representing a Vertex Array Object (VAO).
 */
typedef struct dkb_VAO
{
  GLuint ID;
} dkb_VAO;

/**
 * @brief Initializes a shader with vertex and fragment shader files.
 * 
 * This function compiles and links vertex and fragment shaders and creates a shader program.
 * 
 * @param shader Pointer to the dkb_Shader structure to be initialized.
 * @param vertexPath Path to the vertex shader file.
 * @param fragmentPath Path to the fragment shader file.
 */
void dkb_initShader(dkb_Shader* shader, const char* vertexPath, const char* fragmentPath);
/**
 * @brief Sets a shader as the currently active shader program.
 * 
 * @param shader Pointer to the dkb_Shader structure representing the shader program to be used.
 */
void dkb_useShader(dkb_Shader* shader);
/**
 * @brief Deletes a shader program and releases associated resources.
 * 
 * @param shader Pointer to the dkb_Shader structure representing the shader program to be deleted.
 */
void dkb_deleteShader(dkb_Shader* shader);

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

/**
 * @brief Initializes an Element Buffer Object (EBO) with given indices data.
 * 
 * @param EBO Pointer to the EBO structure to be initialized.
 * @param indices Pointer to the indices data.
 * @param indicesSize Size of the indices data in bytes.
 */
void dkb_initEBO(dkb_EBO* EBO, GLuint* indices, GLsizeiptr indicesSize);
/**
 * @brief Binds an Element Buffer Object (EBO) for use.
 * 
 * @param EBO Pointer to the EBO structure to be bound.
 */
void dkb_bindEBO(dkb_EBO* EBO);
/**
 * @brief Unbinds the currently bound Element Buffer Object (EBO).
 */
void dkb_unbindEBO();
/**
 * @brief Deletes an Element Buffer Object (EBO) and frees its resources.
 * 
 * @param EBO Pointer to the EBO structure to be deleted.
 */
void dkb_deleteEBO(dkb_EBO* EBO);

/**
 * @brief Initializes a Vertex Array Object (VAO).
 * 
 * @param VAO Pointer to the VAO structure to be initialized.
 */
void dkb_initVAO(dkb_VAO* VAO);
/**
 * @brief Binds a Vertex Array Object (VAO) for use.
 * 
 * @param VAO Pointer to the VAO structure to be bound.
 */
void dkb_bindVAO(dkb_VAO* VAO);
/**
 * @brief Unbinds the currently bound Vertex Array Object (VAO).
 */
void dkb_unbindVAO();
/**
 * @brief Deletes a Vertex Array Object (VAO) and frees its resources.
 * 
 * @param VAO Pointer to the VAO structure to be deleted.
 */
void dkb_deleteVAO(dkb_VAO* VAO);
/**
 * @brief Links a Vertex Buffer Object (VBO) attribute to a Vertex Array Object (VAO).
 * 
 * @param VBO Pointer to the VBO structure containing the attribute data.
 * @param layout The layout location of the attribute.
 * @param size The number of components per attribute.
 * @param type The data type of each component.
 * @param stride The stride between consecutive attributes.
 * @param offset The offset of the first component in the buffer.
 */
void dkb_linkAttribute(dkb_VBO* VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset);

#endif // DKB_GRAPHICS_H
