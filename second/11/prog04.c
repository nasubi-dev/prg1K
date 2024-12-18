#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize(int a[], int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    int j = rand() % i;

    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
}

int main(void)
{
  srand((unsigned int)time(NULL));

  int n = 10;
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  randomize(a, n);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}