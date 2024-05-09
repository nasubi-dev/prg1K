#include <stdio.h>

int main(int argc,char* argv[]) {
  double dx;
  int nx;

  printf("dx? ");
  scanf("%lf",&dx);

  printf("dx/2 = %lf\n",dx/2);

  nx = dx;
  printf("nx = %d\n",nx);
  printf("nx/2 = %d\n",nx/2);

  return 0;
}