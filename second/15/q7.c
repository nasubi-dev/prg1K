#include <stdio.h>
#include <stdlib.h>

typedef struct Trial
{
  int speed;
  int distance;
} Trial;

void parseTrial(Trial *trial, char line[256])
{
  sscanf(line, "%d,%d", &trial->speed, &trial->distance);
}

int main(void)
{
  Trial *trial = (Trial *)malloc(sizeof(Trial) * 10);
  Trial *array_all = (Trial *)malloc(sizeof(Trial) * 50);

  // cars.csvを読み込む
  FILE *fp = fopen("./cars.csv", "r");
  if (fp == NULL)
  {
    printf("ファイルを開くことができませんでした。\n");
    return 1;
  }

  // ファイルを読み込む
  int count = 0;
  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    parseTrial(&array_all[count], line);
    count++;
  }

  // ファイルを閉じる
  fclose(fp);

  // 平均二上誤差(Mean Squared Error)が最も小さい直線の傾きaを求める
  double a = 0;
  double upper = 0;
  double lower = 0;
  for (int i = 0; i < count; i++)
  {
    upper += array_all[i].speed * array_all[i].distance;
    lower += array_all[i].speed * array_all[i].speed;
  }
  a = upper / lower;

  printf("a: %f\n", a);

  return 0;
}