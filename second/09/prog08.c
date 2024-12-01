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

void writeToCSV(Earthquake e, FILE *outputFile)
{
  fprintf(outputFile, "%d,", e.year);
  fprintf(outputFile, "%d,", e.month);
  fprintf(outputFile, "%d,", e.day);
  fprintf(outputFile, "%f,", e.latitude);
  fprintf(outputFile, "%f,", e.longitude);
  fprintf(outputFile, "%c\n", e.earthquakeIntensity);
}

void printEarthquake(Earthquake e)
{
  printf("発生日: %d年%d月%d日\n", e.year, e.month, e.day);
  printf("緯度: %f\n", e.latitude);
  printf("経度: %f\n", e.longitude);
  printf("震度: %c\n", e.earthquakeIntensity);
}

double earthquakeIntensityToDouble(char earthquakeIntensity)
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

  FILE *inputFile = fopen("./second/09/h2011_eq.csv", "r");
  if (inputFile == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, DATA_MAX, inputFile) != NULL)
  {
    earthquakes[i++] = parseLine(line);
  }
  fclose(inputFile);

  FILE *outputFile = fopen("h2011_eq_0311.csv", "w");
  fprintf(outputFile, "year,month,day,latitude,longitude,earthquakeIntensity\n");

  for (int j = 0; j < i; j++)
  {
    char earthquakeIntensity = earthquakes[j].earthquakeIntensity;
    double earthquakeIntensityDouble =
        earthquakeIntensityToDouble(earthquakeIntensity);
    int month = earthquakes[j].month;
    int day = earthquakes[j].day;

    if (month != 3 || day != 11)
      continue;
    if (earthquakeIntensityDouble < 4.0)
      continue;

    writeToCSV(earthquakes[j], outputFile);
  }
  fclose(outputFile);

  return 0;
}