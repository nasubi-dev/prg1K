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

void printIrisJudgementByAve(Iris *irisAveVersicolor, Iris *irisAveVirginica,
                             Iris *irisAveSetosa, Iris checkIris)
{
  double distanceVersicolor = 0;
  double distanceVirginica = 0;
  double distanceSetosa = 0;

  distanceVersicolor =
      pow(checkIris.sepal_length - irisAveVersicolor->sepal_length, 2) +
      pow(checkIris.sepal_width - irisAveVersicolor->sepal_width, 2) +
      pow(checkIris.petal_length - irisAveVersicolor->petal_length, 2) +
      pow(checkIris.petal_width - irisAveVersicolor->petal_width, 2);
  distanceVirginica =
      pow(checkIris.sepal_length - irisAveVirginica->sepal_length, 2) +
      pow(checkIris.sepal_width - irisAveVirginica->sepal_width, 2) +
      pow(checkIris.petal_length - irisAveVirginica->petal_length, 2) +
      pow(checkIris.petal_width - irisAveVirginica->petal_width, 2);
  distanceSetosa =
      pow(checkIris.sepal_length - irisAveSetosa->sepal_length, 2) +
      pow(checkIris.sepal_width - irisAveSetosa->sepal_width, 2) +
      pow(checkIris.petal_length - irisAveSetosa->petal_length, 2) +
      pow(checkIris.petal_width - irisAveSetosa->petal_width, 2);

  if (distanceVersicolor < distanceVirginica &&
      distanceVersicolor < distanceSetosa)
  {
    printf("versicolor\n");
  }
  else if (distanceVirginica < distanceVersicolor &&
           distanceVirginica < distanceSetosa)
  {
    printf("virginica\n");
  }
  else if (distanceSetosa < distanceVersicolor &&
           distanceSetosa < distanceVirginica)
  {
    printf("setosa\n");
  }
  else
  {
    printf("error\n");
  }
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

  int virginicaCount = 0;
  int cersicolorCount = 0;
  int setosaCount = 0;

  for (int j = 0; j < i; j++)
  {
    if (strcmp(irises[j].class, "Iris-virginica") == 0)
    {
      irisVirginicas[virginicaCount] = irises[j];
      virginicaCount++;
    }
    else if (strcmp(irises[j].class, "Iris-versicolor") == 0)
    {
      irisCersicolors[cersicolorCount] = irises[j];
      cersicolorCount++;
    }
    else if (strcmp(irises[j].class, "Iris-setosa") == 0)
    {
      irisSetosas[setosaCount] = irises[j];
      setosaCount++;
    }
  }

  Iris irisJudgment1 = {5.7, 4.0, 1.2, 0.2, ""};
  Iris irisJudgment2 = {5.9, 2.9, 4.2, 1.5, ""};
  Iris irisJudgment3 = {5.6, 2.8, 4.8, 2.0, ""};

  Iris irisVirginicaAvg =
      getIrisAvg("Iris-virginica", irisVirginicas, virginicaCount);
  Iris irisCersicolorAvg =
      getIrisAvg("Iris-versicolor", irisCersicolors, cersicolorCount);
  Iris irisSetosaAvg = getIrisAvg("Iris-setosa", irisSetosas, setosaCount);

  printf("[判定1]\n");
  printIrisJudgementByAve(&irisVirginicaAvg, &irisCersicolorAvg, &irisSetosaAvg,
                          irisJudgment1);
  printf("[判定2]\n");
  printIrisJudgementByAve(&irisVirginicaAvg, &irisCersicolorAvg, &irisSetosaAvg,
                          irisJudgment2);
  printf("[判定3]\n");
  printIrisJudgementByAve(&irisVirginicaAvg, &irisCersicolorAvg, &irisSetosaAvg,
                          irisJudgment3);

  return 0;
}
