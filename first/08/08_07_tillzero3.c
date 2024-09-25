#include <stdio.h>

int main(void) {
  int wallet = 1000;
  int amount = 0;

  while (wallet > 0) {
    printf("amount? ");
    scanf("%d", &amount);

    if (amount == 0) {
      printf("取引終了\n");
      break;
    } else if (amount < 0) {
      printf("無効です\n");
    } else {
      wallet -= amount;
      printf("残高: %d\n", wallet);
    }
  }
  return 0;
}
