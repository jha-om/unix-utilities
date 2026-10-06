#include <stddef.h>
#include <stdio.h>
#include <string.h>

void compress() {
  int seen_char = getchar();
  int next_char;
  int count = 1;
  while ((next_char = getchar()) != EOF) {
    if (next_char == seen_char) {
      if (count == 255) {
        putchar(seen_char);
        putchar(255);
        count = 1;
      } else {
        count++;
      }
    } else {
      putchar(seen_char);
      putchar(count);
      seen_char = next_char;
      count = 1;
    }
  }
  putchar(seen_char);
  putchar(count);
}

void decompress() {
  int ch;
  int count;
  while ((ch = getchar()) != EOF) {
    count = getchar();

    if (count == EOF) {
      return;
    }
    for (int i = 0; i < count; i++) {
      putchar(ch);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("<RLE> <compress|decompress>\n");
    return 1;
  }

  if (!strcmp(argv[1], "compress")) {
    compress();
  } else if (!strcmp(argv[1], "decompress")) {
    decompress();
  } else {
    printf("<RLE> <compress|decompress> <file/text>");
    return 1;
  }

  return 0;
}
