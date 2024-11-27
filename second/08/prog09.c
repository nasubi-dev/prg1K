#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 256
#define DATA_MAX 256
#define CLASS_MAX 32

typedef struct iris
{
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char class[CLASS_MAX];
} Iris;

Iris parseIris(char *str)
{
  char *pointer;
  Iris iris;

  pointer = strtok(str, ",");

  iris.sepal_length = atof(pointer);
  pointer = strtok(NULL, ",");
  iris.sepal_width = atof(pointer);
  pointer = strtok(NULL, ",");
  iris.petal_length = atof(pointer);
  pointer = strtok(NULL, ",");
  iris.petal_width = atof(pointer);
  pointer = strtok(NULL, ",");

  pointer[strlen(pointer) - 1] = '\0';
  static char tmp[64] = {'\0'};
  strcpy(iris.class, pointer);

  return iris;
}

Iris getIrisAverage(Iris *iris_list, int size)
{
  Iris aveIris;

  double sepalLengthAvg = 0;
  double sepalWidthAvg = 0;
  double petalLengthAvg = 0;
  double petalWidthAvg = 0;

  for (int j = 0; j < size; j++)
  {
    sepalLengthAvg += iris_list[j].sepal_length;
    sepalWidthAvg += iris_list[j].sepal_width;
    petalLengthAvg += iris_list[j].petal_length;
    petalWidthAvg += iris_list[j].petal_width;
  }

  sepalLengthAvg = sepalLengthAvg / size;
  sepalWidthAvg = sepalWidthAvg / size;
  petalLengthAvg = petalLengthAvg / size;
  petalWidthAvg = petalWidthAvg / size;

  aveIris.sepal_length = sepalLengthAvg;
  aveIris.sepal_width = sepalWidthAvg;
  aveIris.petal_length = petalLengthAvg;
  aveIris.petal_width = petalWidthAvg;

  return aveIris;
}

Iris getIrisSD(Iris *iris_list, int size)
{
  Iris aveIris = getIrisAverage(iris_list, size);
  Iris stdIris;

  for (int i = 0; i < size; i++)
  {
    stdIris.sepal_length +=
        pow(iris_list[i].sepal_length - aveIris.sepal_length, 2);
    stdIris.sepal_width +=
        pow(iris_list[i].sepal_width - aveIris.sepal_width, 2);
    stdIris.petal_length +=
        pow(iris_list[i].petal_length - aveIris.petal_length, 2);
    stdIris.petal_width +=
        pow(iris_list[i].petal_width - aveIris.petal_width, 2);
  }

  stdIris.sepal_length = sqrt(stdIris.sepal_length / size);
  stdIris.sepal_width = sqrt(stdIris.sepal_width / size);
  stdIris.petal_length = sqrt(stdIris.petal_length / size);
  stdIris.petal_width = sqrt(stdIris.petal_width / size);

  return stdIris;
}

void printIrisJudgeBySample(Iris *irises, int size, Iris checkIris)
{
  double distance = 100.0;
  int index = 0;

  for (int i = 0; i < size; i++)
  {
    double newDistance =
        pow(checkIris.sepal_length - irises[i].sepal_length, 2) +
        pow(checkIris.sepal_width - irises[i].sepal_width, 2) +
        pow(checkIris.petal_length - irises[i].petal_length, 2) +
        pow(checkIris.petal_width - irises[i].petal_width, 2);

    if (distance > newDistance)
    {
      distance = newDistance;
      index = i;
    }
  }

  printf("%s\n", irises[index].class);
}

int main(void)
{
  char line[LINE_MAX];
  Iris lists[DATA_MAX];
  Iris irisVirginicas[DATA_MAX];
  Iris irisVersicolors[DATA_MAX];
  Iris irisSetosas[DATA_MAX];

  FILE *file;
  file = fopen("iris.data", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    exit(1);
  }

  int i = 0;
  while (fgets(line, LINE_MAX, file) != NULL)
  {
    lists[i++] = parseIris(line);
  }
  fclose(file);

  int virginicaCount = 0;
  int versicolorCount = 0;
  int setosaCount = 0;

  for (int j = 0; j < i; j++)
  {
    if (strcmp(lists[j].class, "Iris-virginica") == 0)
    {
      irisVirginicas[virginicaCount++] = lists[j];
    }
    else if (strcmp(lists[j].class, "Iris-versicolor") == 0)
    {
      irisVersicolors[versicolorCount++] = lists[j];
    }
    else if (strcmp(lists[j].class, "Iris-setosa") == 0)
    {
      irisSetosas[setosaCount++] = lists[j];
    }
  }

  int size = i;
  Iris irisJudgment1 = {5.7, 4.0, 1.2, 0.2, ""};
  Iris irisJudgment2 = {5.9, 2.9, 4.2, 1.5, ""};
  Iris irisJudgment3 = {5.6, 2.8, 4.8, 2.0, ""};

  printf("[判定1]\n");
  printIrisJudgeBySample(lists, size, irisJudgment1);
  printf("[判定2]\n");
  printIrisJudgeBySample(lists, size, irisJudgment2);
  printf("[判定3]\n");
  printIrisJudgeBySample(lists, size, irisJudgment3);

  return 0;
}