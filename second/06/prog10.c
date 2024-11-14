#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[128] = "foo,bar,hoge,fuga";

  char *token = strtok(str, ",");
  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, ",");
  }

  return 0;
}