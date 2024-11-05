#include <stdio.h>

void swap(int *pa, int *pb)
{
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void bubble(int *arr, int num)
{
  for (int i = num - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (*(arr + j) > *(arr + j + 1))
        swap(arr + j, arr + j + 1);
    }
  }
  printf("bubbleSortしたよ\n");
}

int main(void)
{
  int array[] = {10, 42, 11, 0, 10000, 12};
  const int num = sizeof array / sizeof(int);

  for (int i = 0; i < num; i++)
  {
    printf("%d\n", array[i]);
  }

  printf("\n");

  bubble(array, num);


  for (int i = 0; i < num; i++)
  {
    printf("%d\n", array[i]);
  }

  return 0;
}