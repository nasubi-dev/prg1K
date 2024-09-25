#include <stdio.h>

int linearfunc(int x) { return 2 * x + 1; }

int main(void)
{
  for (int i = 0; i <= 4; i++)
  {
    printf("f(%d)=%d\n", i, linearfunc(i));
  }
  return 0;
}