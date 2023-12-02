#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int main(int argc, char *argv[]) {
  FILE *f = fopen("input.txt", "r");

  if (NULL == f) {
    return 1;
  }

  char line_buf[512];
  int sum = 0;

  while (NULL != fgets(line_buf, sizeof(line_buf), f)) {
    char *end;
    strtol(line_buf + 5, &end, 10);

    int maxred = 0, maxgreen = 0, maxblue = 0;

    for (char *l = end + 2; '\0' != *l; ++l) {
      int a = strtol(l, &end, 10);

      if (a == 0)
        continue;

      if (strncmp(end + 1, "red", 3) == 0) {
        maxred = max(maxred, a);
        l = end + 3;
      } else if (strncmp(end + 1, "green", 5) == 0) {
        maxgreen = max(maxgreen, a);
        l = end + 5;
      } else {
        maxblue = max(maxblue, a);
        l = end + 4;
      }
    }

    sum += maxred * maxgreen * maxblue;
  }

  printf("Answer: %d\n", sum);

  fclose(f);

  return 0;
}
