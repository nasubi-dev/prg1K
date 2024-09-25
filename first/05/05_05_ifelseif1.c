#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b;

  printf("a? ");
  scanf("%d", &a);
  printf("b? ");
  scanf("%d", &b);

  if (a == 0) {
    printf("aは0です\n");
  } else if (a >= b) {
    printf("aはb以上です\n");
  } else {
    printf("aはb未満です\n");
  }

  return 0;
}
