#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int n = 10;

  int prev = 1;
  int x = 1;

  for (int k = 0; k < 10; k++)
  {
    printf("%d: %d\n", k + 1, prev);
    int tmp = x;
    x += prev;
    prev = tmp;
  }

  return 0;
}