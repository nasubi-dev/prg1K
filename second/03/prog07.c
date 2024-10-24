#include <stdio.h>

int main(void)
{
  int a = 10;
  int *pa = &a;

  printf("aのアドレス: %d\n", a);
  printf("paの値: %p\n", pa);
  printf("paのアドレス: %p\n", &pa);

  return 0;
}