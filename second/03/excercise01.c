#include <math.h>
#include <stdio.h>

void getAvgSD(int a, int b, double *avg, double *sd)
{
  *avg = (a + b) / 2.0;
  *sd = sqrt(pow(a - *avg, 2) + pow(a - *avg, 2));
}

int main(void)
{
  int a, b;
  double avg, sd;

  scanf("%d, %d", &a, &b);

  getAvgSD(a, b, &avg, &sd);

  printf("avg:%.2lf ", avg);
  printf("sd:%.2lf\n", sd);

  return 0;
}