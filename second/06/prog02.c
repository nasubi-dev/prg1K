#include <math.h>
#include <stdio.h>

int main(void)
{
  int r = 10;

  printf("Area: %f\n", M_PI * r * r);
  printf("Circumference: %f\n", 2 * M_PI * r);

  return 0;
}