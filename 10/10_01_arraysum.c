#include <stdio.h>

int main(void)
{
  int evenNumbers[5] = {0};
  int sum = 0;

  for (int i = 0; i < 5; i++)
    evenNumbers[i] += (i + 1) * 2;
  for (int i = 0; i < 5; i++)
    sum += evenNumbers[i];

  printf("合計 = %d\n", sum);

  return 0;
}