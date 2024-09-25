#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;
  int x1, x10, x100;

  printf("x? ");
  scanf("%d", &x);

  x100 = x / 100 % 10;
  x10 = x / 10 % 10;
  x1 = x % 10;

  printf("reverse x =  %d%d%d\n", x1, x10, x100);

  return 0;
}
