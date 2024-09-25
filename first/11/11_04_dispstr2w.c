#include <stdio.h>

int main(void)
{
  char inputText[11] = {'\0'};
  int index = 0;

  printf("入力(10文字以内): ");
  scanf("%s", inputText);

  while (index < sizeof(inputText))
  {
    putchar(inputText[index]);
    index++;
  }
  printf("\n");

  return 0;
}