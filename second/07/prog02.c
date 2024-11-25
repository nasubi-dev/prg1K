#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *p = (char *)malloc(5 * sizeof(char));

  strcpy(p, "hoge");
  printf("%s\n", p);

  free(p);

  return 0;
}