#include <stdio.h>

int main(void)
{
  char ch = ' ';
  int isPlus = 1;
  int answer = 0;
  int n = 0;

  printf("equation? ");
  while (ch != '=')
  {
    ch = getchar();

    switch (ch)
    {
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
      n = 0;
      while (1)
      {
        if (ch == ' ')
          break;

        n = n * 10 + (int)ch - 48;
        ch = getchar();
      }
      answer += isPlus ? n : -n;

      break;
    }
  }
  printf("answer: %d\n", answer);

  return 0;
}