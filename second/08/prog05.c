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
}

void printIris(Iris iris)
{
  printf("sepal_length: %f\n", iris.sepal_length);
  printf("sepal_width: %f\n", iris.sepal_width);
  printf("petal_length: %f\n", iris.petal_length);
  printf("petal_width: %f\n", iris.petal_width);
  printf("class: %s\n", iris.class);
}

int main(void)
{
  char line[256];
  char *dst[5];

  FILE *file;
  Iris *irises = (Iris *)malloc(sizeof(Iris) * 150);

  file = fopen("iris.data", "r");
  if (file == NULL)
  {
    perror("ファイルを開けませんでした。\n");
    return 1;
  }

  int count = 0;
  while (fgets(line, sizeof(line), file) != NULL)
  {
    parseIris(&irises[count], line);
    count++;
  }
  fclose(file);

  for (int i = 0; i < count; i++)
  {
    printIris(irises[i]);
  }

  free(irises);

  return 0;
}