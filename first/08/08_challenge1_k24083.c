#include <stdio.h>

int main(void) {
  int input;
  int isFirst = 1;

  printf("input? ");
  scanf("%d", &input);

  int i = 2;
  while (i <= input) {
    if (input % i != 0) {
      i += 1;
      continue;
    }

    if (isFirst) {
      printf("%d", i);
      isFirst = 0;
    } else {
      printf(", %d", i);
    }

    input /= i;
  }

  printf("\n");

  return 0;
}
