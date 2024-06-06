#include <stdio.h>

int main(void) {
  int w = 0;
  int h = 0;

  printf("w h? ");
  scanf("%d %d", &w, &h);

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) putchar('#');

    putchar('\n');
  }

  return 0;
}
