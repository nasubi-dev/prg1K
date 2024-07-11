#include <stdio.h>

void printFunc(void);

int main(void)
{
  printFunc();

  return 0;
}

void printFunc(void)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", i + 1);
  }
}