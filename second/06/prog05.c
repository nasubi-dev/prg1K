#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void)
{
  char line[MAX];
  FILE *fp = fopen("./second/06/meibo.txt", "r");

  if (fp == NULL)
  {
    printf("File not found.\n");
    exit(1);
  }

  while (fgets(line, MAX, fp) != NULL)
  {
    printf("%s", line);
  }

  fclose(fp);
  return 0;
}