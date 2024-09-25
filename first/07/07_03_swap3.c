#include <stdio.h>

int main(void)
{
  int x = 0;
  int y = 0;
  int z = 0;
  int temp = 0;

  printf("x y z? ");
  scanf("%d %d %d", &x, &y, &z);

  if (x > y)
  {
    temp = x;
    x = y;
    y = temp;
  }
  if (x > z)
  {
    temp = x;
    x = z;
    z = temp;
  }
  if (y > z)
  {
    temp = y;
    y = z;
    z = temp;
  }

  printf("%d %d %d\n", x, y, z);
  return 0;
}
