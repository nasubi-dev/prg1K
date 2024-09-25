#include <stdio.h>
void showBin(int c)
{
  printf("%d", (c / 64) % 2);
  printf("%d", (c / 32) % 2);
  printf("%d", (c / 16) % 2);
  printf("%d", (c / 8) % 2);
  printf("%d", (c / 4) % 2);
  printf("%d", (c / 2) % 2);
  printf("%d", (c / 1) % 2);
  printf("\n");
}
int main()
{
  showBin(5 / 2); // 5 の半分
  showBin(5);     // 5
  showBin(5 * 2); // 5 の 2 倍
  showBin(20);    // 5 の 4 (=2*2) 倍
  showBin(64);
  return 0;
}