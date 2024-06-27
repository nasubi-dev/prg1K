#include <stdio.h>

int main(void)
{
  char inputText[21] = {'\0'};
  int isPalindrome = 0;
  int textLength = 0;

  printf("input(20文字以下): ");
  scanf("%s", inputText);

  for (int i = 0; i < 21; i++)
  {
    if (inputText[i] == '\0')
    {
      textLength = i;
      break;
    }
  }

  for (int i = 0; i < textLength / 2; i++)
  {
    if (inputText[i] != inputText[textLength - i - 1])
    {
      isPalindrome = 1;
      break;
    }
  }

  printf("%s\n", isPalindrome ? "回文NG" : "回文OK");

  return 0;
}