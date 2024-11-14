#include <stdio.h>

int main(void)
{
  FILE *fp = fopen("./second/06/number.txt", "a");

  if (fp == NULL)
  {
    printf("File not found.\n");
    return 1;
  }

  for (int i = 0; i < 100; i++)
  {
    fprintf(fp, "%d\n", 100 + i);
  }

  fclose(fp);

  return 0;
}