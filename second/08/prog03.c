#include <stdio.h>

typedef struct Iris
{
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char class[32];
} Iris;

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
  Iris iris1 = {6.7, 3.0, 5.2, 2.3, "Iris-virginica"};
  Iris iris2 = {7.0, 3.2, 4.7, 1.4, "Iris-versicolor"};

  printIris(iris1);
  printf("\n");
  printIris(iris2);

  return 0;
}