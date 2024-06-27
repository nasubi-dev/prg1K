#include <math.h>
#include <stdio.h>

int main(void) {
  int heights[5] = {0};
  int weights[5] = {0};
  int THRESHOLD = 23;
  double bmi, standardWeight;

  for (int i = 0; i < 5; i++) {
    printf("%d人目の身長と体重? ", i + 1);
    scanf("%d %d", &heights[i], &weights[i]);
  }

  printf("--- しきい値を超えた人 ---\n");

  for (int i = 0; i < 5; i++) {
    bmi = weights[i] / pow(heights[i] / 100.0, 2.0);

    if (bmi > THRESHOLD) {
      standardWeight = (heights[i] - 100) * 0.9;

      printf(
        "%d人目のBMI: %f, 標準体重との差: %f\n",
        i + 1,
        bmi,
        weights[i] - standardWeight
      );
    }
  }
  return 0;
}