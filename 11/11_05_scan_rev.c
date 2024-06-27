#include <stdio.h>

int main(void)
{
  char inputText[6] = {'\0'};
  int index = 0;

  printf("input: ");
  scanf("%s", inputText);

  for (int i = 5; i >= 0; i--)
    printf("%c", inputText[i]);

  printf("\n");

  return 0;
}