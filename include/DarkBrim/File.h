#ifndef DKB_FILE_H
#define DKB_FILE_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Retrieves the contents of a file.
 * 
 * This function reads the contents of the file located at the specified path and returns
 * a pointer to a buffer containing the file contents. The caller is responsible for
 * freeing the memory allocated for the buffer.
 * 
 * @param path The path to the file to be read.
 * @return A pointer to a buffer containing the file contents, or an empty string ("") if an error occurs.
 */
const char* dkb_getFileContents(const char* path);

#endif // DKB_FILE_H
