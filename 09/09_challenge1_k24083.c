#include <stdio.h>

int main(void) {
  char ch = ' ';
  int isPlus = 1;
  int answer = 0;
  int n;

  printf("equation? ");
  while (ch != '=') {
    ch = getchar();

    switch (ch) {
      case ' ':
      case '=':
      case '\n':
      case '\t':
        break;

      case '+':
        isPlus = 1;
        break;

      case '-':
        isPlus = 0;
        break;

      default:
        n = (int)ch - 48;
        answer += isPlus ? n : -n;
        break;
    }
  }
  printf("answer: %d\n", answer);

  return 0;
}
