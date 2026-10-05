#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  char *word = argv[1];
  if (sizeof(word) == 0) {
    printf("pass the word to look for. Right now it's empty\n");
    return 1;
  }
  for (int i = 2; i < argc; i++) {
    char *file = argv[i];
    if (sizeof(file) == 0) {
      printf("pass the file to look for the word. Right now it's empty\n");
      return 1;
    }
    char line[1024];
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file: [%s]\n", argv[i]);
      return 1;
    }
    printf("\nFile: %s\n", argv[i]);
    // size_t n;
    // while ((n = fread(line, 1, sizeof(line), fp)) > 0) {
    //   if (strstr(line, word)) {
    //     if (fwrite(word, 1, n, stdout) != n) {
    //       fclose(fp);
    //       return 1;
    //     }
    //   }
    // }
    while (fgets(line, sizeof(line), fp)) {
      if (strstr(line, word)) {
        printf("%s", line);
      }
    }
    fclose(fp);
  }
  return 0;
}
