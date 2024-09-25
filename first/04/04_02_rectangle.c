#include <stdio.h>

int main(int argc, const char* argv[]) {
  double width, height;

  printf("width? ");
  scanf("%lf", &width);

  printf("height? ");
  scanf("%lf", &height);

  printf("area = %f\n", width * height);

  return 0;
}
