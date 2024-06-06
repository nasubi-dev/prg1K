#include <stdio.h>

int main(void) {
  int wallet = 1000;
  int amount = 0;

  while (wallet > 0) {
    printf("amount? ");
    scanf("%d", &amount);

    wallet -= amount;

    printf("残高: %d\n", wallet);
  }
  return 0;
}
