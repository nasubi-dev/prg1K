#include <math.h>
#include <stdio.h>


int main(void)
{
  int deg = 0;

  while (deg <= 360)
  {
    double rad = deg * M_PI / 180;
    printf("sinの値が: %dのとき､%fです｡\n", deg, sin(rad));

    deg += 10;
  }

  return 0;
}