
#include <stdio.h>

int main(int argc, char* argv[]) {
  int height;
  int weight;
  double standardWeight;
  double bmi;

  printf("height? ");
  scanf("%d", &height);
  printf("weight? ");
  scanf("%d", &weight);

  standardWeight = (height - 100) * 0.9;
  bmi = weight / (height * height * 0.0001);

  printf("standardWeight = %lf\n",standardWeight);
  printf("BMI = %lf\n",bmi);

  return 0;
}