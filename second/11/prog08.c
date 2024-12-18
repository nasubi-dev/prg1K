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

int iris2index(char *class)
{
  if (strcmp(class, "Iris-virginica") == 0)
  {
    return 0;
  }
  else if (strcmp(class, "Iris-versicolor") == 0)
  {
    return 1;
  }
  else if (strcmp(class, "Iris-setosa") == 0)
  {
    return 2;
  }
  else
  {
    return -1;
  }
}

void printConfusionMatrix(char *title, double res[3][3])
{
  printf("縦：正解 (%s)\n横：推定結果\n", title);
  printf("            virginica versicolor setosa\n");
  printf("virginica : %9.2f %10.2f  %5.2f\n", res[0][0], res[0][1], res[0][2]);
  printf("versicolor: %9.2f %10.2f  %5.2f\n", res[1][0], res[1][1], res[1][2]);
  printf("setosa    : %9.2f %10.2f  %5.2f\n", res[2][0], res[2][1], res[2][2]);
}

void printCorrectRate(double res[3][3])
{
  double correct_rate[3][3] = {{0}};
  for (int i = 0; i < 3; i++)
  {
    double total = res[i][0] + res[i][1] + res[i][2];
    for (int j = 0; j < 3; j++)
    {
      correct_rate[i][j] = res[i][j] / total;
    }
  }
  printConfusionMatrix("正解率", correct_rate);
}

int main(void)
{
  char line[256];
  char *dst[5];

  FILE *file;
  Iris *array_all = (Iris *)malloc(sizeof(Iris) * 20);
  Iris *array_learn = (Iris *)malloc(sizeof(Iris) * 20);
  Iris *array_test = (Iris *)malloc(sizeof(Iris) * 20);

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

  double res[3][3] = {{0}};
  for (int i = 0; i < test_length; i++)
  {
    double distance_min = 100;
    Iris near_iris;

    for (int j = 0; j < learn_length; j++)
    {
      double distance = irisDistance(array_test[i], array_learn[j]);
      if (distance < distance_min)
      {
        distance_min = distance;
        near_iris = array_learn[j];
      }
    }

    int index_test = iris2index(array_test[i].class);
    int index_learn = iris2index(near_iris.class);
    res[index_test][index_learn]++;
  }

  printConfusionMatrix("正解数", res);
  printf("\n");
  printCorrectRate(res);

  free(array_all);
  free(array_learn);
  free(array_test);

  return 0;
}