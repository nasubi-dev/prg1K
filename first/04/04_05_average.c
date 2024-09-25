#include <stdio.h>

int main(int argc, const char* argv[]) {
  int h1, h2, h3;

  printf("No.1? ");
  scanf("%d", &h1);
  printf("No.2? ");
  scanf("%d", &h2);
  printf("No.3? ");
  scanf("%d", &h3);
  
  printf("average = %f\n", (h1 + h2 + h3) / 3.0);
  return 0;
}
