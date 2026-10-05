#include <stdio.h>
#include <stdlib.h>

#define CHUNK 4096

int main(int argc, char *argv[]) {
  // No files given: nothing to do, exit successfully.
  // (Real cat would read stdin here; the project says to just exit 0.)
  char buf[CHUNK];

  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    // Stream the file in fixed-size chunks: memory use stays constant no
    // matter how big the file is, and output starts immediately.
    // fread/fwrite are binary-safe (no problem with embedded '\0' bytes).
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
      if (fwrite(buf, 1, n, stdout) != n) {
        fclose(fp);
        exit(1);
      }
    }

    fclose(fp);
  }

  return 0;
}
