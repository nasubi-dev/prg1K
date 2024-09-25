#include <stdio.h>

int main(void)
{
  char inputText[11] = {'\0'};

  printf("入力(10文字以内): ");
  scanf("%s", inputText);

  for (int i = 0; i < sizeof(inputText); i++)
    printf("%c", inputText[i]);

  printf("\n");

  return 0;
}