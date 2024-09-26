#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));

  int n, min, max;

  printf("min: ");
  scanf("%d", &min);
  printf("max: ");
  scanf("%d", &max);

  if (min > max)
  {
    printf("値変えてね");
    return 0;
  }

  n = rand() % (max - min + 1) + min;
  printf("%d\n", n);

  return 0;
}