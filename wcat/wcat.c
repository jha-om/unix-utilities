#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("<wcat>: No file provided. {file1, file2}\n");
    exit(0);
  }
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("<wcat>: cannot open file.\n");
      exit(1);
    }

    // now reading the file given in the fopen pathname
    size_t bufferSize = 128;
    size_t currLen = 0;

    char *buffer = malloc(bufferSize);
    if (buffer == NULL) {
      printf("<wcat>: Memory allocation failed.\n");
      exit(1);
    }
    buffer[0] = '\0';
    while (fgets(buffer + currLen, bufferSize - currLen, fp)) {
      // printf("%s\n", buffer);
      // printf("\n-------before---------\n");
      // printf("\ncurrent Length: %zu\n", currLen);

      currLen += strlen(buffer + currLen);

      // printf("\n-------after---------\n");
      // printf("\ncurrent Length: %zu\n", currLen);
      // printf("\n----------------\n");

      // if (currLen && buffer[currLen - 1] == '\n') {
      if (currLen == bufferSize - 1) {
        // printf("***** required to double the bufferSize. *****\n");
        bufferSize *= 2;
        char *temp = realloc(buffer, bufferSize);
        if (temp == NULL) {
          printf("<wcat>: Memory allocation failed.\n");
          exit(1);
        }
        buffer = temp;
      }
    }
    printf("\nFile: %s\n\n", argv[i]);
    printf("%s\n", buffer);
    // printf("Buffer size: %zu\n", bufferSize);

    // de-allocating the memory space used
    free(buffer);
    // closing the file

    if (fclose(fp) == 0) {
      printf("file is closed.\n");
    }
  }
  return 0;
}
