#include <stdio.h>

int main(void)
{
  int a = 100;
  int b = 200;

  printf("a,b %d,%d\n", a, b);

  int *pa = &a;
  int *pb = &b;

  *pa = 10;
  *pb = 20;

  printf("a,b %d,%d\n", a, b);

  return 0;
}