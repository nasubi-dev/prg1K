#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *p;
  if ((p = (int *)malloc(10 * sizeof(int))) == NULL)
  {
    printf("No enough memory.\n");
    exit(1);
  }

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