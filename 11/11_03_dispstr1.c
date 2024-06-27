#include <stdio.h>

int main(void)
{
  char array[] = "abcde";

  printf("一文字ずつ印字: ");

  for (int i = 0; i < sizeof(array); i++)
    printf("%c", array[i]);

  printf("\n");

  return 0;
}