#include <math.h>
#include <stdio.h>

double calcArea(double r) { return r * r * M_PI; }
double calcCircumference(double r) { return 2 * r * M_PI; }

int main(void)
{
  double r;

  printf("input r: ");
  scanf("%lf", &r);
  printf("%f %f\n", calcArea(r), calcCircumference(r));
}
