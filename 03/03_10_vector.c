#include <stdio.h>

int main(int argc, char *argv[]) {
  int y;
  int x;
  printf("(y,x)? ");
  scanf("%d %d", &y,&x);
  printf("(%d,%d) -> (%d,%d)\n",y,x,y*y,x*x);
  return 0;
}