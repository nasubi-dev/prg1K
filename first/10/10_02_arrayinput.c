#include <stdio.h>

int main(void) {
  int heights[5] = {0};
  double sum = 0;

  for (int i = 0; i < 5; i++) {
    printf("%d人目の身長? ", i + 1);
    scanf("%d", &heights[i]);
  }

  for (int i = 0; i < 5; i++) sum += heights[i];

  double avg = sum / 5;
  printf("平均身長 = %f\n", avg);

  return 0;
}