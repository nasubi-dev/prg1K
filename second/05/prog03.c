#include <stdio.h>

int main(void)
{
  int i;
  char a[][5] = {"LISP", "C", "Ada"};
  char *p[] = {"PAUL", "X", "MAC"};

  int arrayOfA = sizeof(a) / sizeof(a[0]);
  for (i = 0; i < arrayOfA; i++)
  {
    printf("a[%d] = \"%s\"\n", i, a[i]);
  }

  int arrayOfP = sizeof(p) / sizeof(p[0]);
  for (i = 0; i < arrayOfP; i++)
  {
    printf("p[%d] = \"%s\"\n", i, p[i]);
  }

  return 0;
}