#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Iris
{
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char class[32];
  int count;
} Iris;

void parseIris(Iris *iris, char line[256])
{
  char *pointer;

  pointer = strtok(line, ",");

  iris->sepal_length = atof(pointer);
  pointer = strtok(NULL, ",");
  iris->sepal_width = atof(pointer);
  pointer = strtok(NULL, ",");
  iris->petal_length = atof(pointer);
  pointer = strtok(NULL, ",");
  iris->petal_width = atof(pointer);
  pointer = strtok(NULL, ",");
  pointer[strlen(pointer) - 1] = '\0';
  strcpy(iris->class, pointer);
  iris->count = 1;
}

int getIrisIndex(Iris *irises, Iris iris, int irisesLen)
{
  for (int i = 0; i < irisesLen; i++)
  {
    if (strcmp(irises[i].class, iris.class) == 0)
      return i;
  }
  return -1;
}

void addIris(Iris *irises, Iris *iris, int *irisesLen)
{
  int index = getIrisIndex(irises, *iris, *irisesLen);
  if (index == -1)
  {
    irises[*irisesLen] = *iris;
    *irisesLen += 1;
  }
  else
  {
    irises[index].sepal_length += iris->sepal_length;
    irises[index].sepal_width += iris->sepal_width;
    irises[index].petal_length += iris->petal_length;
    irises[index].petal_width += iris->petal_width;
    irises[index].count += 1;
  }
}

void divIris(Iris *iris)
{
  iris->sepal_length /= iris->count;
  iris->sepal_width /= iris->count;
  iris->petal_length /= iris->count;
  iris->petal_width /= iris->count;
}

void printIris(Iris iris)
{
  printf("%s(avg)\n", iris.class);
  printf("sepal_length: %f\n", iris.sepal_length);
  printf("sepal_width: %f\n", iris.sepal_width);
  printf("petal_length: %f\n", iris.petal_length);
  printf("petal_width: %f\n", iris.petal_width);
}

int main(void)
{
  char line[256];
  char *dst[5];

  FILE *file;
  Iris irises[3];
  int irisesLen = 0;

  file = fopen("iris.data", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    return 1;
  }

  while (fgets(line, sizeof(line), file) != NULL)
  {
    Iris tmpIris;
    parseIris(&tmpIris, line);
    addIris(irises, &tmpIris, &irisesLen);
  }
  fclose(file);

  for (int i = 0; i < irisesLen; i++)
  {
    divIris(&irises[i]);
    printIris(irises[i]);
  }

  return 0;
}