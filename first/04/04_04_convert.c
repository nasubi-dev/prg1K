#include <stdio.h>

int main(int argc, const char* argv[]) {
  double dx, dy;
  int nx, ny;

  printf("nx ny? ");
  scanf("%d %d", &nx, &ny);

  dx = nx;
  dy = ny;

  printf("nx/ny = %d\n", nx / ny);
  printf("dx/ny = %f\n", dx / ny);
  printf("nx/dy = %f\n", dx / ny);

  return 0;
}
