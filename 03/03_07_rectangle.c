#include <stdio.h>

int main(int argc, char *argv[]) {
  int a;
  int b;
  int perimeter;
  int area;
  printf("a b? ");
  scanf("%d,%d",&a,&b);
  perimeter = a+a+b+b;
  printf("perimeter = %d \n",perimeter);
  area=a*b;
  printf("area = %d \n",area);
  return 0;
}