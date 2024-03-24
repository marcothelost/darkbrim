# Executable
add_executable(
  darkbrim
  Main.c
)

# Libraries
target_link_libraries(darkbrim PRIVATE DarkBrim m GL GLEW glfw)

# Include Directory
target_include_directories(darkbrim PRIVATE ${CMAKE_SOURCE_DIR}/include)
