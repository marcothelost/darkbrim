# Library
add_library(
  DarkBrim
  Core.c
  File.c
  Graphics.c
  Window.c
)

# Include Directory
target_include_directories(DarkBrim PRIVATE ${CMAKE_SOURCE_DIR}/include)
