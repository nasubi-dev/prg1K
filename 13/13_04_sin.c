#include <math.h>
#include <stdio.h>

int main(void)
{
  double theta = 0;
  double rad = 0;

  printf("input: ");
  scanf("%lf", &theta);

  rad = theta / 180.0 * M_PI;
  printf("sin (%lf) = %lf\n", theta, sin(rad));

  return 0;
}