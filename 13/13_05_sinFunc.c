#include <math.h>
#include <stdio.h>

double deg2Rad(double);

int main(void)
{
  double theta = 0;
  double rad = 0;

  printf("input: ");
  scanf("%lf", &theta);
  printf("sin (%lf) = %lf\n", theta, sin(deg2Rad(theta)));

  return 0;
}

double deg2Rad(double theta) { return theta / 180.0 * M_PI; }