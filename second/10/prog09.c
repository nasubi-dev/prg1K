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

double intensity2double(char earthquakeIntensity)
{
  switch (earthquakeIntensity)
  {
  case '1':
  case '2':
  case '3':
  case '4':
  case '7':
    return earthquakeIntensity - '0';
  case 'A':
  case 'B':
  case 'C':
  case 'D':
    return earthquakeIntensity - 'A' * 0.5 + 5;
  default:
    return 0.0;
  }
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

  int count = 0;
  for (int j = 0; j < i; j++)
  {
    char intensity = earthquakes[j].earthquakeIntensity;
    double intensityDouble = intensity2double(intensity);
    if (intensityDouble >= 5.0)
      count++;
  }

  printf("震度5以上の地震は%d回発生しました。\n", count);

  return 0;
}