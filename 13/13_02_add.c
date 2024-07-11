#include <stdio.h>

void addOf(int, int);

int main(void)
{
  int a = 5;
  int b = 10;
  int res;

  addOf(a, b);
  return 0;
}

void addOf(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a + b);
  return 0;
}