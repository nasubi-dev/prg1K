#include <stdio.h>

void swap(int *pa, int *pb)
{
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void sort(int *pa, int *pb)
{
  if (*pa > *pb)
    swap(pa, pb);
}

int main(void)
{
  int a = 10;
  int b = 20;

  printf("a: %d, b: %d\n", a, b);
  sort(&a, &b);
  printf("a: %d, b: %d\n", a, b);

  return 0;
}