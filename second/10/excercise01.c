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

int main()
{
  char line[LINE_MAX] = "";
  Earthquake earthquakes[DATA_MAX];

  FILE *inputFile = fopen("./second/10/h2011_eq.csv", "r");
  if (inputFile == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, LINE_MAX, inputFile) != NULL)
  {
    earthquakes[i++] = parseLine(line);
  }
  fclose(inputFile);

  for (int j = 0; j < i - 1; j++)
  {
    for (int k = j + 1; k < i; k++)
    {
      if (earthquakes[j].latitude > earthquakes[k].latitude)
      {
        Earthquake tmp = earthquakes[j];
        earthquakes[j] = earthquakes[k];
        earthquakes[k] = tmp;
      }
    }
  }

  int latRangeMin = (int)((earthquakes[0].latitude) / 2) * 2;
  int count = 0;
  for (int j = 0; j < i; j++)
  {
    if (earthquakes[j].latitude > latRangeMin + 2)
    {
      printf("%d-%d度 %d回\n", latRangeMin, latRangeMin + 2, count);
      count = 1;
      latRangeMin += 2;
    }
    else
    {
      count++;
    }

    if (j == i - 1)
    {
      printf("%d-%d度 %d回\n", latRangeMin, latRangeMin + 2, count);
    }
  }

  return 0;
}