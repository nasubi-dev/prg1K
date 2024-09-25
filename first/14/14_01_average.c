#include <stdio.h>

int main(void)
{
  int height[3] = {0};
  double average;

  for (int i = 0; i < 3; i++)
  {
    printf("%d人目の身長は? ", i + 1);
    scanf("%d", &height[i]);
  }

  average = (height[0] + height[1] + height[2]) / 3.0;
  printf("平均身長は %f\n", average);

  return 0;
}