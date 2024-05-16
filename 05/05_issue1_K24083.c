#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;
  printf("x? ");
  scanf("%d", &x);

  if (x == 0) {
    printf("2の倍数ではありません\n");
    printf("3の倍数ではありません\n");
  } else {
    if (x % 2){
      printf("2の倍数ではありません\n");
    } else{
      printf("2の倍数です\n");
    }

    if (x % 3){
      printf("3の倍数ではありません\n");
    } else {
      printf("3の倍数です\n");
    }
  }

  return 0;
}
