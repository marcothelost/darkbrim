# Library
add_library(
  DarkBrim
  Core.c
)

# Include Directory
target_include_directories(DarkBrim PRIVATE ${CMAKE_SOURCE_DIR}/include)
