#include <math.h>
#include <stdio.h>

int main(void)
{
  int r;

  printf("半径: ");
  scanf("%d", &r);

  double circumference = 2 * M_PI * r;

  double area = r * r * M_PI;

  printf("円周: %f\n", circumference);
  printf("面積: %f\n", area);

  return 0;
}