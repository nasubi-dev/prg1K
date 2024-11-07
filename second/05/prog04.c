#include <stdio.h>
#include <string.h>

int main(void)
{
  char *str = "abcd";

  int l = strlen(str);
  for (int i = 0; i < l; i++)
  {
    printf("%c\n", str[i]);
  }

  return 0;
}