# Library
add_library(
  DarkBrim
  Core.c
  File.c
  Keys.c
  Graphics.c
  Window.c
  Space.c
  Camera.c
  Debug.c
)

# Include Directory
target_include_directories(DarkBrim PRIVATE ${CMAKE_SOURCE_DIR}/include)
