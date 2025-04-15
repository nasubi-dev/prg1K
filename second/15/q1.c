#include <stdio.h>

int main(void)
{
  // cars.csvを読み込む
  FILE *fp = fopen("./cars.csv", "r");
  if (fp == NULL) {
    printf("ファイルを開くことができませんでした。\n");
    return 1;
  }

  // ファイルを読み込む
  char line[50];
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }

  // ファイルを閉じる
  fclose(fp);

  return 0;
}