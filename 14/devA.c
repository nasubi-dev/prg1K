#include <stdio.h>

void devA(int, int, int);

int main()
{
  devA(0, 0, 0);
  devA(0, 0, 1);
  devA(0, 1, 0);
  devA(0, 1, 1);
  devA(1, 0, 0);
  devA(1, 0, 1);
  devA(1, 1, 0);
  devA(1, 1, 1);
  printf("\n");
  return 0;
}

void devA(int a, int b, int c)
{
  if (a == 1)
    printf("GO ");
  else if (a != 1 && b == 1 && c == 1)
    printf("GO ");
  else if (a != 1 && b != 1 && c == 1)
    printf("GO ");
  else
    printf("NO ");
}