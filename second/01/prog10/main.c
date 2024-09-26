#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned int)time(NULL));
  int n = rand() % 3 + 3;

  printf("%d\n", n);

  return 0;
}