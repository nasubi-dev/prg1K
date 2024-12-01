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

  int earthquakeIntensityCount[16] = {0};
  for (int j = 0; j < i; j++)
  {
    int index = 0;
    switch (earthquakes[j].earthquakeIntensity)
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
      index = earthquakes[j].earthquakeIntensity - 'A' + 8;
      break;
    default:
      index = earthquakes[j].earthquakeIntensity - '0';
      break;
    }
    earthquakeIntensityCount[index]++;
  }

  printf("震度1: %d\n", earthquakeIntensityCount[1]);
  printf("震度2: %d\n", earthquakeIntensityCount[2]);
  printf("震度3: %d\n", earthquakeIntensityCount[3]);
  printf("震度4: %d\n", earthquakeIntensityCount[4]);
  printf("震度5弱: %d\n", earthquakeIntensityCount[8]);
  printf("震度5強: %d\n", earthquakeIntensityCount[9]);
  printf("震度6弱: %d\n", earthquakeIntensityCount[10]);
  printf("震度6強: %d\n", earthquakeIntensityCount[11]);
  printf("震度7: %d\n", earthquakeIntensityCount[7]);

  free(earthquakes);

  return 0;
}
