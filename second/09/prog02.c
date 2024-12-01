#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

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
  char line[MAX_LINE_LENGTH] = "2011,3,11,36.249500,137.581667,4\n";
  Earthquake e;

  e = parseLine(line);

  printEarthquake(e);

  return 0;
}
