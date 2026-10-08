#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wzip: [file1] [file2]...\n");
    return 1;
  }
  int seen_char;
  int count = 0, first = 1;
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "error reading file.\n");
      return 1;
    }
    int next_char;
    while ((next_char = fgetc(fp)) != EOF) {
      if (first) {
        seen_char = next_char;
        first = 0;
        count = 1;
        if (seen_char == EOF) {
          printf("empty file, no compression required.\n");
          return 1;
        }
      } else if (next_char == seen_char) {
        count++;
      } else {
        char c = (char)seen_char;
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&c, sizeof(char), 1, stdout);
        seen_char = next_char;
        count = 1;
      }
    }
    fclose(fp);
  }
  if (!first) {
    char c = (char)seen_char;
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&c, sizeof(char), 1, stdout);
  }

  return 0;
}
