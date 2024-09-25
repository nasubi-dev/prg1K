#include <stdio.h>
int main(void)
{
  char ch;
  printf("text? ");

  while ((ch = getchar()) != '\n')
  {
    switch (ch)
    {
    case ' ':
      putchar('\n');
      break;
    default:
      putchar(ch);
      break;
    }
  }
  printf("\n");
  return 0;
}