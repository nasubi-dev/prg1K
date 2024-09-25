#include <stdio.h>

void devB(int, int, int);

int main()
{
  devB(0, 0, 0); // no
  devB(0, 0, 1);
  devB(0, 1, 0); // no
  devB(0, 1, 1);
  devB(1, 0, 0);
  devB(1, 0, 1);
  devB(1, 1, 0);
  devB(1, 1, 1);
  printf("\n");
  return 0;
}

void devB(int a, int b, int c)
{
  if (a || c)
    printf("GO ");
  else
    printf("NO ");
}