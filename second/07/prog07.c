#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *p = (int *)malloc(sizeof(int));
  int len;

  for (len = 1;; len++)
  {
    if ((p = (int *)realloc(p, len * sizeof(int))) == NULL)
    {
      printf("No enough memory.\n");
      exit(1);
    }
    scanf("%d", &p[len - 1]);
    if (p[len - 1] < 0)
      break;
  }

  for (int i = 0; i < len - 1; i++)
  {
    printf("%d\n", p[i]);
  }

  free(p);

  return 0;
}