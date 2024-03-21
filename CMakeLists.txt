# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "darkbrim")
set(OpenGL_GL_PREFERENCE "LEGACY")

# Project Name
project(${PROJECT_NAME})

# Subdirectories
add_subdirectory(examples)

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
