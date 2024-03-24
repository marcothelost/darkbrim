#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DarkBrim/Core.h"
#include "DarkBrim/Graphics.h"
#include "DarkBrim/Window.h"

// Window Settings
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "DarkBrim";

// Settings
const unsigned int INFO_LOG_SIZE = 512;

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f, -0.5f, 0.f, 1.f, 1.f, 1.f,
  -0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f,  0.5f, 0.f, 1.f, 1.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  0, 3, 2,
};

int main()
{
  // Initializing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

  // GLFw Window
  dkb_Window window;
  dkb_initWindow(&window, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
  if (window.glfwInstance == NULL)
  {
    glfwTerminate();
    return EXIT_FAILURE;
  }
  dkb_useWindow(&window);

  // Initializing GLEW
  GLenum glewErr = glewInit();
  if (glewErr != GLEW_OK)
  {
    fprintf(stderr, "Failed to initialize GLEW!\n");
    glfwDestroyWindow(window.glfwInstance);
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Clear Color
  GLclampf red   = 0.0f;
  GLclampf green = 0.0f;
  GLclampf blue  = 0.0f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  // Shader Program
  dkb_Shader defaultShader;
  dkb_initShader(&defaultShader, "assets/Shaders/default.vert", "assets/Shaders/default.frag");

  // VAO, VBO, and EBO
  dkb_VAO VAO;
  dkb_VBO VBO;
  dkb_EBO EBO;

  dkb_initVAO(&VAO);
  dkb_initVBO(&VBO, vertices, sizeof(vertices));
  dkb_initEBO(&EBO, indices, sizeof(indices));

  dkb_bindVAO(&VAO);
  dkb_bindVBO(&VBO);
  dkb_bindEBO(&EBO);

  dkb_linkAttribute(&VBO, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  dkb_linkAttribute(&VBO, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  dkb_unbindVAO();
  dkb_unbindVBO();
  dkb_unbindEBO();

  // DarkBrim Initialization
  dkb_initialize();

  // Version Info
  dkb_printEngineInfo();
  printf("\n");
  dkb_printVersionInfo();

  // Display Mode
  dkb_useLineMode();

  // Main Loop
  while (!glfwWindowShouldClose(window.glfwInstance))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    dkb_useShader(&defaultShader);
    dkb_bindVAO(&VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window.glfwInstance);
  }

  // Termination
  dkb_deleteVAO(&VAO);
  dkb_deleteVBO(&VBO);
  dkb_deleteEBO(&EBO);
  dkb_deleteShader(&defaultShader);
  glfwDestroyWindow(window.glfwInstance);
  glfwTerminate();
  return EXIT_SUCCESS;
}
