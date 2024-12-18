#include <math.h>
#include <stdio.h>

int main(void)
{
  int n = 10;
  int a = 4;

  int sum = 0;
  for (int k = 0; k <=10; k++)
  {
    sum += pow(a, n - k);
  }

  printf("Sum: %d\n", sum);

  return 0;
}