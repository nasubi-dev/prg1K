#include <stdio.h>

int main(void)
{
  int arr[3] = {1, 2, 3};

  for (int i = 0; i < 3; i++)
  {
    printf("%p\n", &arr[i]);
  }

  return 0;
}