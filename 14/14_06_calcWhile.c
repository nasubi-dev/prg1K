#include <stdio.h>

int main(void)
{
  int n;

  printf("n? ");
  scanf("%d", &n);

  int sum = 0;
  int i = 1;
  while (i <= n)
  {
    sum += i;
    i++;
  }

  printf("1から%dまでの和は %d\n", n, sum);

  return 0;
}