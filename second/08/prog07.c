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

Iris parseIris(char line[256])
{
  Iris iris;
  iris.sepal_length = atof(strtok(line, ","));
  iris.sepal_width = atof(strtok(NULL, ","));
  iris.petal_length = atof(strtok(NULL, ","));
  iris.petal_width = atof(strtok(NULL, ","));
  strcpy(iris.class, strtok(NULL, "\n"));

  return iris;
}

void printIris(Iris iris)
{
  printf("%s(avg)\n", iris.class);
  printf("sepal_length: %f\n", iris.sepal_length);
  printf("sepal_width: %f\n", iris.sepal_width);
  printf("petal_length: %f\n", iris.petal_length);
  printf("petal_width: %f\n", iris.petal_width);
}

Iris getIrisAvg(char class[CLASS_MAX], Iris *iris_list, int size)
{
  Iris sumIris = {0, 0, 0, 0, ""};

  for (int i = 0; i < size; i++)
  {
    sumIris.sepal_length += iris_list[i].sepal_length;
    sumIris.sepal_width += iris_list[i].sepal_width;
    sumIris.petal_length += iris_list[i].petal_length;
    sumIris.petal_width += iris_list[i].petal_width;
  }

  Iris aveIris;
  aveIris.sepal_length = sumIris.sepal_length / size;
  aveIris.sepal_width = sumIris.sepal_width / size;
  aveIris.petal_length = sumIris.petal_length / size;
  aveIris.petal_width = sumIris.petal_width / size;
  strcpy(aveIris.class, class);

  return aveIris;
}

Iris getIrisSD(char class[CLASS_MAX], Iris *iris_list, int size)
{
  Iris aveIris = getIrisAvg(class, iris_list, size);
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

int main(void)
{
  Iris irises[DATA_MAX];
  char line[LINE_MAX];

  Iris irisVirginicas[DATA_MAX];
  Iris irisCersicolors[DATA_MAX];
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
    irises[i++] = parseIris(line);
  }

  fclose(file);

  int irisVirginicaCount = 0;
  int irisCersicolorCount = 0;
  int irisSetosaCount = 0;

  for (int j = 0; j < i; j++)
  {
    if (strcmp(irises[j].class, "Iris-virginica") == 0)
    {
      irisVirginicas[irisVirginicaCount] = irises[j];
      irisVirginicaCount++;
    }
    else if (strcmp(irises[j].class, "Iris-versicolor") == 0)
    {
      irisCersicolors[irisCersicolorCount] = irises[j];
      irisCersicolorCount++;
    }
    else if (strcmp(irises[j].class, "Iris-setosa") == 0)
    {
      irisSetosas[irisSetosaCount] = irises[j];
      irisSetosaCount++;
    }
  }

  printf("[平均]\n");
  printIris(getIrisAvg("Iris-virginica", irisVirginicas, irisVirginicaCount));
  printIris(
      getIrisAvg("Iris-versicolor", irisCersicolors, irisCersicolorCount));
  printIris(getIrisAvg("Iris-setosa", irisSetosas, irisSetosaCount));

  printf("[標準偏差]\n");
  printIris(getIrisSD("Iris-virginica", irisVirginicas, irisVirginicaCount));
  printIris(getIrisSD("Iris-versicolor", irisCersicolors, irisCersicolorCount));
  printIris(getIrisSD("Iris-setosa", irisSetosas, irisSetosaCount));

  return 0;
}
