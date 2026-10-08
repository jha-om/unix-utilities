#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wunzip: [file1] [file2]...\n");
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");

    if (fp == NULL) {
      fprintf(stderr, "error in file opening.\n");
      return 1;
    }

    int count;
    char ch;

    while (fread(&count, sizeof(int), 1, fp) == 1) {
      if (fread(&ch, sizeof(char), 1, fp) != 1) {
        fprintf(stderr, "wunzip: corrupt file: %s\n", argv[i]);
        fclose(fp);
        return 1;
      }

      for (int j = 0; j < count; j++) {
        fwrite(&ch, sizeof(char), 1, stdout);
      }
    }
    fclose(fp);
  }
  return 0;
}
