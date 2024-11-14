#include <ctype.h>
#include <stdio.h>

int main(void) {
  char str[100];

  printf("input: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }

  printf("output: %s\n", str);

  return 0;
}