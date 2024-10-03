#include <stdio.h>

int draw_figure(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}