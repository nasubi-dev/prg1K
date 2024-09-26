#include <stdio.h>
#define LOOP_COUNT 10
#define BREAK_NUM 3

int main(void)
{
  for (int i = 1; i <= LOOP_COUNT; i++)
  {
    printf("hoge");
    if (i % BREAK_NUM == 0)
    {
      printf("\n");
    }
  }

  return 0;
}