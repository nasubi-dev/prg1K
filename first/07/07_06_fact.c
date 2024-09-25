#include <stdio.h>

int main(int argc, const char *argv[])
{
  int x = 0;
  int n = 0;
  int temp = 0;

  printf("x n? ");
  scanf("%d %d", &x, &n);

  temp = x;
  for (int i = 1; i < n; i++) temp *= x;

  printf("%d^%d = %d\n", x, n, temp);

  return 0;
}
