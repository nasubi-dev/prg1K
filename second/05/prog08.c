#include <stdio.h>
#include <string.h>

void swap_str_ptr(char **a, char **b)
{
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void)
{
  char *a = "AB";
  char *b = "XY";

  printf("a: %s\n", a);
  printf("b: %s\n", b);

  swap_str_ptr(&a, &b);
  printf("\nAfter swapping:\n");

  printf("a: %s\n", a);
  printf("b: %s\n", b);

  return 0;
}