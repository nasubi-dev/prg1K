#include <stdio.h>

int main(void)
{
  int n = 10;

  int sum = 0;
  int x = 1;

  for (int k = 1; k <= 10; k++)
  {
    sum += x;
    x += 2;
  }

  printf("Sum: %d\n", sum);

  return 0;
}