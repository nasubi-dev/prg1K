#include <stdio.h>

int main(void)
{
  int x, y;
  char a, b;

  printf("int xのアドレス: %p\n", &x);
  printf("int yのアドレス: %p\n", &y);
  printf("char aのアドレス: %p\n", &a);
  printf("char bのアドレス: %p\n", &b);

  return 0;
}