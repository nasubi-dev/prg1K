#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 100
#define DATA_MAX 10625

typedef struct earthquake
{
  int year;
  int month;
  int day;
  double latitude;
  double longitude;
  char earthquakeIntensity;
} Earthquake;

Earthquake parseLine(char line[])
{
  Earthquake e;
  e.year = atoi(strtok(line, ","));
  e.month = atoi(strtok(NULL, ","));
  e.day = atoi(strtok(NULL, ","));
  e.latitude = atof(strtok(NULL, ","));
  e.longitude = atof(strtok(NULL, ","));
  e.earthquakeIntensity = strtok(NULL, ",")[0];

  return e;
}

void printEarthquake(Earthquake e)
{
  printf("発生日: %d年%d月%d日\n", e.year, e.month, e.day);
  printf("緯度: %f\n", e.latitude);
  printf("経度: %f\n", e.longitude);
  printf("震度: %c\n", e.earthquakeIntensity);
}

int main()
{
  char line[LINE_MAX] = "";
  Earthquake earthquakes[DATA_MAX];

  FILE *file;
  file = fopen("./second/09/h2011_eq.csv", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, DATA_MAX, file) != NULL)
  {
    earthquakes[i] = parseLine(line);
    i++;
  }
  fclose(file);

  for (int j = 0; j < i; j++)
  {
    printEarthquake(earthquakes[j]);
  }

  return 0;
}
