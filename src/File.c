#include "DarkBrim/File.h"

const char* dkb_getFileContents(const char* path)
{
  FILE* file;

  file = fopen(path, "rb");
  if (file == NULL)
  {
    fprintf(stderr, "Failed to open file (%s)!\n", path);
    return "";
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  char* buffer = (char*)malloc(size + 1);
  if (buffer == NULL)
  {
    fprintf(stderr , "Failed to allocate memory for file (%s)!\n", path);
    fclose(file);
    return "";
  }

  size_t bytesRead = fread(buffer, 1, size, file);
  if (bytesRead != size)
  {
    fprintf(stderr, "Failed to read file (%s)!\n", path);
    fclose(file);
    return "";
  }

  buffer[size] = '\0';
  fclose(file);

  return buffer;
}
