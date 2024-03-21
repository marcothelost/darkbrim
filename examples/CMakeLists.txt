# Executable
add_executable(
  darkbrim
  Main.c
)

# Libraries
target_link_libraries(darkbrim PRIVATE GL GLEW glfw)
