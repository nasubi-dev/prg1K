#include <stdio.h>
#include <stdlib.h>

typedef struct Trial
{
  int speed;
  int distance;
} Trial;

void parseTrial(Trial *trial, char line[50])
{
  sscanf(line, "%d,%d", &trial->speed, &trial->distance);
}

// 期待する回答 speed: 10,distance :18
void dispTrial(Trial *trial)
{
  printf("speed: %d, distance: %d\n", trial->speed, trial->distance);
}

int main(void)
{
  Trial *trial = (Trial *)malloc(sizeof(Trial));
  Trial *array_all = (Trial *)malloc(sizeof(Trial) * 10);

  // cars.csvを読み込む
  FILE *fp = fopen("./cars.csv", "r");
  if (fp == NULL)
  {
    printf("ファイルを開くことができませんでした。\n");
    return 1;
  }

  // ファイルを読み込む
  int count = 0;
  char line[50];
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    parseTrial(&array_all[count], line);
    count++;
  }

  // ファイルを閉じる
  fclose(fp);

  for (int i = 0; i < count; i++)
  {
    dispTrial(&array_all[i]);
  }

  return 0;
}