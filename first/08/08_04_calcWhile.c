#include <stdio.h>

int main(void) {
  int x, sum;

  sum = 0;
  while (x != 0) {
    printf("x? ");
    scanf("%d", &x);

    sum += x;

    printf("sum: %d\n", sum);
  }

  printf("end\n");

  return 0;
}
