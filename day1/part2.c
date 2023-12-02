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
      case 'o':
        if (strncmp(l, "one", 3) == 0) {
          if (firstdigit == 0)
            firstdigit = 1;
          lastdigit = 1;
        }
        break;
      case 't':
        if (strncmp(l, "two", 3) == 0) {
          if (firstdigit == 0)
            firstdigit = 2;
          lastdigit = 2;
        } else if (strncmp(l, "three", 5) == 0) {
          if (firstdigit == 0)
            firstdigit = 3;
          lastdigit = 3;
        }
        break;
      case 'f':
        if (strncmp(l, "four", 4) == 0) {
          if (firstdigit == 0)
            firstdigit = 4;
          lastdigit = 4;
        } else if (strncmp(l, "five", 4) == 0) {
          if (firstdigit == 0)
            firstdigit = 5;
          lastdigit = 5;
        }
        break;
      case 's':
        if (strncmp(l, "six", 3) == 0) {
          if (firstdigit == 0)
            firstdigit = 6;
          lastdigit = 6;
        } else if (strncmp(l, "seven", 5) == 0) {
          if (firstdigit == 0)
            firstdigit = 7;
          lastdigit = 7;
        }
        break;
      case 'e':
        if (strncmp(l, "eight", 5) == 0) {
          if (firstdigit == 0)
            firstdigit = 8;
          lastdigit = 8;
        }
        break;
      case 'n':
        if (strncmp(l, "nine", 4) == 0) {
          if (firstdigit == 0)
            firstdigit = 9;
          lastdigit = 9;
        }
        break;
      default:
        break;
      }
    }

    sum += firstdigit * 10 + lastdigit;
  }

  printf("Answer: %d\n", sum);

  fclose(f);

  return 0;
}
