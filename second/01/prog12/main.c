#include <stdio.h>

int main(void)
{
  int height, weight;
  double bmi;

  printf("身長(cm): ");
  scanf("%d", &height);
  printf("体重(kg): ");
  scanf("%d", &weight);

  bmi = weight / (height * height / 10000.0);

  printf("BMI: %3.2f\n", bmi);

  if (bmi < 18.5)
  {
    printf("やせ\n");
  }
  else if (bmi < 25)
  {
    printf("標準\n");
  }
  else if (bmi < 30)
  {
    printf("肥満\n");
  }
  else
  {
    printf("高度肥満\n");
  }

  return 0;
}