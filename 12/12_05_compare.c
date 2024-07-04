#include <stdio.h>

int main(void)
{
  int a = 0;
  int b = 0;

  printf("a b? ");
  scanf("%d %d", &a, &b);

  printf("大きい方の値は %d\n", a > b ? a : b);

  return 0;
}