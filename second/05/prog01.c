#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[128] = "abc";
  char str2[] = "cde";
  char *str = "fgh";

  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int len3 = strlen(str);

  int size1 = sizeof str1;
  int size2 = sizeof str2;
  int size3 = sizeof str;

  printf("str1[128] : strlen = %d, sizeof = %d\n", len1, size1);
  printf("str2[] : strlen = %d, sizeof = %d\n", len2, size2);
  printf("str : strlen = %d, sizeof = %d\n", len3, size3);

  return 0;
}