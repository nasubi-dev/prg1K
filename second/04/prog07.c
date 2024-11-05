#include <stdio.h>

void scaleBy10(int *p, int len)
{
  for (int i = 0; i < len; i++)
  {
    *(p + i) *= 10;
  }
}

int main(void)
{
  int a[5] = {10, 20, 30, 40, 50};
  int b[4] = {3, 4, 5, 6};

  scaleBy10(a, 5);
  scaleBy10(b, 4);

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", a[i]);
  }

  printf("\n");

  for (int i = 0; i < 4; i++)
  {
    printf("%d\n", b[i]);
  }

  return 0;
}