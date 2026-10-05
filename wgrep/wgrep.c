#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  char *word = argv[1];

  // if files are not provided;
  if (argc == 2) {
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
      if (strstr(line, word)) {
        printf("%s", line);
      }
    }

    free(line);

    return 0;
  }

  for (int i = 2; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");

    if (fp == NULL) {
      printf("wgrep: cannot open file: [%s]\n", argv[i]);
      return 1;
    }

    char *line = NULL;
    size_t len = 0;

    printf("\nFile: %s\n", argv[i]);
    // why fread() will not work?
    // or why streaming of data will not work?
    //
    // the reason is that fread() reads in chunks so it will not read the whole
    // line, and that is what we needed because we need entire line of the word

    // size_t n;
    // while ((n = fread(line, 1, sizeof(line), fp)) > 0) {
    //   if (strstr(line, word)) {
    //     if (fwrite(word, 1, n, stdout) != n) {
    //       fclose(fp);
    //       return 1;
    //     }
    //   }
    // }
    while (getline(&line, &len, fp) != -1) {
      if (strstr(line, word)) {
        printf("%s", line);
      }
    }
    free(line);
    fclose(fp);
  }
  return 0;
}
