#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void randomize(Iris array_all[], int n)
{
  srand((unsigned int)time(NULL));

  for (int i = n - 1; i > 0; i--)
  {
    int j = rand() % i;

    Iris tmp = array_all[i];
    array_all[i] = array_all[j];
    array_all[j] = tmp;
  }
}

double irisDistance(Iris a, Iris b)
{
  double distance = 0;
  distance += pow(a.sepal_length - b.sepal_length, 2);
  distance += pow(a.sepal_width - b.sepal_width, 2);
  distance += pow(a.petal_length - b.petal_length, 2);
  distance += pow(a.petal_width - b.petal_width, 2);
  distance = sqrt(distance);
  return distance;
}

int main(void)
{
  char line[256];
  char *dst[5];

  FILE *file;
  Iris *array_all = (Iris *)malloc(sizeof(Iris) * 10);
  Iris *array_learn = (Iris *)malloc(sizeof(Iris) * 10);
  Iris *array_test = (Iris *)malloc(sizeof(Iris) * 10);

  file = fopen("./second/11/iris.data", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    return 1;
  }

  int count = 0;
  while (fgets(line, sizeof(line), file) != NULL)
  {
    parseIris(&array_all[count], line);
    count++;
  }
  fclose(file);

  randomize(array_all, count);

  int learn_length = count / 5 * 4;
  int test_length = count - learn_length;

  for (int i = 0; i < learn_length; i++)
  {
    array_learn[i] = array_all[i];
  }

  for (int i = 0; i < test_length; i++)
  {
    array_test[i] = array_all[learn_length + i];
  }

  for (int i = 0; i < test_length; i++)
  {
    double distance_min = 100;
    Iris near_iris;

    for (int j = 0; j < 120; j++)
    {
      double distance = irisDistance(array_test[i], array_learn[j]);
      if (distance < distance_min)
      {
        distance_min = distance;
        near_iris = array_learn[j];
      }
    }

    printf("推定結果: %s, ", near_iris.class);
    printf("正解: %s ,", array_test[i].class);
    printf("近侍度: %f\n", distance_min);
  }

  free(array_all);
  free(array_learn);
  free(array_test);

  return 0;
}