#include <stdio.h>

void times10(int *p)
{
  for (int i = 0; i < 5; i++)
  {
    *(p + i) *= 10;
  }
}

int main(void)
{
  int a[5] = {10, 20, 30, 40, 50};

  times10(a);

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", a[i]);
  }

  return 0;
}