#include <stdio.h>

int main(int argc, const char *argv[])
{
  int sum = 0;

  for (int i = 0; i <= 10; i++)
    sum += i;

  printf("%d\n", sum);

  return 0;
}
