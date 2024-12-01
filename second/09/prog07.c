#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 100

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
  Earthquake *earthquakes = (Earthquake *)malloc(5 * sizeof(Earthquake));

  FILE *file;
  file = fopen("./second/09/h2011_eq.csv", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, LINE_MAX, file) != NULL)
  {
    earthquakes[i++] = parseLine(line);
    int size = (i + 2) * sizeof(Earthquake);
    earthquakes = (Earthquake *)realloc(earthquakes, size);
  }
  fclose(file);

  int dateOfEachMonthes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int earthquakeIntensityCount[365] = {0};
  int earthquakeIntensitySum = 0;

  for (int j = 0; j < i; j++)
  {
    int index = earthquakes[j].month - 1;
    earthquakeIntensityCount[index] += 1;
    earthquakeIntensitySum += 1;
  }

  double earthquakeIntensityAverage = (double)earthquakeIntensitySum / 365;
  printf("平均: %f\n", earthquakeIntensityAverage);

  double earthquakeIntensityVar = 0;
  for (int j = 0; j < 365; j++)
  {
    earthquakeIntensityVar +=
        pow(earthquakeIntensityCount[j] - earthquakeIntensityAverage, 2);
  }
  earthquakeIntensityVar /= 365;
  double earthquakeIntensityStd = sqrt(earthquakeIntensityVar);
  printf("標準偏差: %f\n", earthquakeIntensityStd);

  return 0;
}
