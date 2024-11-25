#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *p = (int *)malloc(4 * sizeof(int));
  p[0] = 100;
  p[1] = 200;
  p[2] = 300;
  p[3] = 400;

  printf("%d\n", p[0]);
  printf("%d\n", p[1]);
  printf("%d\n", p[2]);
  printf("%d\n", p[3]);

  free(p);

  return 0;
}