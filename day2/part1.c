#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *f = fopen("input.txt", "r");

  if (NULL == f) {
    return 1;
  }

  int max_red = 12, max_green = 13, max_blue = 14;

  char line_buf[512];
  int sum = 0;

  while (NULL != fgets(line_buf, sizeof(line_buf), f)) {
    char *end;
    int id = strtol(line_buf + 5, &end, 10);

    for (char *l = end + 2; '\0' != *l; ++l) {
      int a = strtol(l, &end, 10);

      if (a == 0)
        continue;

      if (strncmp(end + 1, "red", 3) == 0) {
        if (a > max_red)
          goto impossible_game;
        l = end + 4;
      } else if (strncmp(end + 1, "green", 5) == 0) {
        if (a > max_green)
          goto impossible_game;
        l = end + 6;
      } else {
        if (a > max_blue)
          goto impossible_game;
        l = end + 5;
      }
    }

    sum += id;
  impossible_game:
  }

  printf("Answer: %d\n", sum);

  fclose(f);

  return 0;
}
