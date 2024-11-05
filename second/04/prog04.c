#include <stdio.h>

int main(void)
{
  int arr[5] = {1, 2, 3, 4, 5};
  int *pa = arr;

  printf("先頭ポインタ: %p\n\n", pa);

  for (int i = 0; i < 5; i++)
  {
    printf("pa +%d: %p\n", i, pa + i);
  }

  printf("\n");

  for (int i = 0; i < 5; i++)
  {
    printf("arr[%d]: %p\n", i, &arr[i]);
  }

  return 0;
}