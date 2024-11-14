#include <stdio.h>
#define MAX 256

int main(void)
{
  FILE *fp = fopen("./second/06/meibo.txt", "a");

  if (fp == NULL)
  {
    printf("File not found.\n");
    return 1;
  }

  for (int i = 0; i < 100; i++)
  {
    char name[MAX];
    printf("Name (exit => !): ");
    scanf("%s", name);
    if (name[0] == '!')
      break;
    fprintf(fp, "%s\n", name);
  }

  fclose(fp);

  return 0;
}