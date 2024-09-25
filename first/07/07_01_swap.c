#include <stdio.h>

int main(void)
{
  int x = 0;
  int y = 0;
  int temp = 0;

  printf("x y? ");
  scanf("%d %d", &x, &y);

  temp = x;
  x = y;
  y = temp;

  printf("%d %d\n", x, y);

  return 0;
}
