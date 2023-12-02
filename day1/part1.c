#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *f = fopen("input.txt", "r");

  if (NULL == f) {
    return 1;
  }

  char line_buf[512];
  int sum = 0;
  while (NULL != fgets(line_buf, sizeof(line_buf), f)) {
    int firstdigit = 0, lastdigit = 0;
    for (char *l = line_buf; '\0' != *l; ++l) {
      int d;
      switch (*l) {
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        d = *l - '0';
        if (firstdigit == 0)
          firstdigit = d;
        lastdigit = d;
        break;
      }
    }

    sum += firstdigit * 10 + lastdigit;
  }

  printf("Answer: %d\n", sum);

  fclose(f);

  return 0;
}
