#include <stdio.h>
int linear(int x)
{
  return 2 * x + 1;
}

int main(void)
{
  int a;
  for (int i = 0; i < 5; i++)
  {
    a = linear(i);
    printf("f(%d)=%d\n", i, a);
  }
  return 0;
}