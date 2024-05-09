#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;
  printf("x? ");
  scanf("%d", &x);

  if (x % 2)
    printf("odd\n");
  else
    printf("even\n");

  return 0;
}
