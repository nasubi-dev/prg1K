#include <stdio.h>
#include <string.h>

void my_strcpy(char *a, char *b)
{
  int i = 0;
  while (b[i] != '\0')
  {
    a[i] = b[i];
    i++;
  }
  a[i] = '\0';
}

int main(void)
{
  char a[128] = "abc";
  char b[128];

  my_strcpy(b, a);
  printf("a: %s\n", a);
  printf("b: %s\n", b);

  return 0;
}