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

void sort3(int *a, int *b, int *c)
{
  sort(a, b);
  sort(a, c);
  sort(b, c);
}

int main(void)
{
  int a = 30;
  int b = 20;
  int c = 10;

  printf("%d, %d, %d\n", a, b, c);
  sort3(&a, &b, &c);
  printf("%d, %d, %d\n", a, b, c);

  return 0;
}