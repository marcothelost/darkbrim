#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DarkBrim/Core.h"
#include "DarkBrim/Keys.h"
#include "DarkBrim/Graphics.h"
#include "DarkBrim/Window.h"
#include "DarkBrim/Space.h"
#include "DarkBrim/Debug.h"

// Window Settings
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "DarkBrim";

// Camera Settings
const float CAMERA_FOV    = 60.f;
const float CAMERA_ASPECT = (float)WINDOW_WIDTH / WINDOW_HEIGHT;
const float CAMERA_NEAR   = 0.1f;
const float CAMERA_FAR    = 100.f;

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
  dkb_initializeGlfw();

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

  // Camera Position
  dkb_Vec3 cameraPosition = dkb_vec3(0.f, 0.f, -3.f);

  // Main Loop
  while (!glfwWindowShouldClose(window.glfwInstance))
  {
    glfwPollEvents();
    dkb_updateWindow(&window);

    if (dkb_isKeyPressed(window.glfwInstance, W))
    {
      cameraPosition.z += 10.f * window.deltaTime;
    }
    if (dkb_isKeyPressed(window.glfwInstance, S))
    {
      cameraPosition.z -= 10.f * window.deltaTime;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    dkb_useShader(&defaultShader);

    dkb_Mat4 model = dkb_mat4(1.f);
    dkb_Mat4 view = dkb_mat4(1.f);
    dkb_Mat4 proj = dkb_mat4(1.f);
    
    view = dkb_translate_mat4(&view, &cameraPosition);
    proj = dkb_projection_mat4(
      CAMERA_FOV,
      window.aspect,
      CAMERA_NEAR,
      CAMERA_FAR
    );

    dkb_shader_setMat4(&defaultShader, "model", &model);
    dkb_shader_setMat4(&defaultShader, "view", &view);
    dkb_shader_setMat4(&defaultShader, "proj", &proj);

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
