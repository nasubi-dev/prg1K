#include <stdio.h>

int addOf(int, int);

int main(void)
{
  int a = 0, b = 0;

  printf("a b? ");
  scanf("%d %d", &a, &b);

  printf("和は %d\n", addOf(a, b));

  return 0;
}

int addOf(int a, int b) { return a + b; }