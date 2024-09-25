#include <stdio.h>

int main(void)
{
  int wallet = 1000;
  int amount;

  while (1)
  {
    printf("amount? ");
    scanf("%d", &amount);
    wallet -= amount;
    if (amount == 0 || wallet <= 0)
      break;
    printf("残高: %d\n", wallet);
  }
  printf("取引終了\n");

  return 0;
}