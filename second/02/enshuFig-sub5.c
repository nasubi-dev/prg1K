#include <stdio.h>

int draw_figure(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (j == size - i - 1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}