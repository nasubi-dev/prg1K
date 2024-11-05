#include <stdio.h>

int main(void)
{
  double arr[3] = {1.0, 2.0, 3.0};

  for (int i = 0; i < 3; i++)
  {
    printf("%p\n", &arr[i]);
  }

  return 0;
}