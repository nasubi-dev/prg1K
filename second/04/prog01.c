#include <stdio.h>

void dameSwap(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
  printf("DAMESWAPの終わり:%d,%d\n", a, b);
}

void swap(int *pa, int *pb)
{
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
  printf("SWAPの終わり:%d,%d\n", *pa, *pb);
}

int main(void)
{
  int a = 10;
  int b = 20;

  printf("MAIN:%d,%d\n", a, b);
  // dameSwap(a, b);
  swap(&a, &b);
  printf("MAINの中:%d,%d\n", a, b);

  return 0;
}