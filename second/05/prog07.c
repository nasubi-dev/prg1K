#include <stdio.h>
#include <string.h>

void swap_str(char *a, char *b)
{
  char tmp[128];
  strcpy(tmp, a);
  strcpy(a, b);
  strcpy(b, tmp);
}

int main(void)
{
  char a[128] = "abcde";
  char b[128] = "xyz";

  printf("a: %s\n", a);
  printf("b: %s\n", b);

  swap_str(a, b);
  printf("\nAfter swapping:\n");

  printf("a: %s\n", a);
  printf("b: %s\n", b);

  return 0;
}