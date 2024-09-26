#include <stdio.h>

int main(void)
{
  for (int i = 1; i <= 10; i++)
  {
    printf("hoge");
    if (i % 3 == 0)
    {
      printf("\n");
    }
  }

  return 0;
}