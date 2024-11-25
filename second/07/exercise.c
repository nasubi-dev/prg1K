#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double average(int *p, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += p[i];
  }
  return (double)sum / n;
}

double standard_deviation(int *p, int n, double avg)
{
  double deviation_sum = 0;
  for (int i = 0; i < n; i++)
  {
    deviation_sum += (p[i] - avg) * (p[i] - avg);
  }
  return sqrt(deviation_sum / n);
}

int main(void)
{
  int *p = (int *)malloc(sizeof(int));
  int n;
  int sum = 0;

  printf("n? ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    if ((p = (int *)realloc(p, (i + 1) * sizeof(int))) == NULL)
    {
      printf("No enough memory.\n");
      exit(1);
    }
    scanf("%d", &p[i]);
    sum += p[i];
    if (p[i] < 0)
      break;
  }

  double avg = average(p, n);
  printf("平均: %f\n", avg);

  double std_deviation = standard_deviation(p, n, avg);
  printf("標準偏差: %f\n", std_deviation);

  free(p);

  return 0;
}