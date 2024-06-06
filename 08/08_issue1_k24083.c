#include <stdio.h>

int main(void) {
  int bank = 1000, wallet = 1000, amount = 0;
  while (bank > 0 && wallet > 0) {
    printf("amount? ");
    scanf("%d", &amount);

    if (amount > 0) {
      bank -= amount;
      wallet += amount;
    } else if (amount < 0) {
      wallet -= -amount;
      bank += -amount;
    } else {
      printf("取引終了\n");
      break;
    }

    printf("銀行: %d 財布: %d\n", bank, wallet);
  }
  return 0;
}
