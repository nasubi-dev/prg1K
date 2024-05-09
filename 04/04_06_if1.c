#include <stdio.h>

int main(int arg,char* argv[]) {
  int a;

  printf("a? ");
  scanf("%d",&a);

  if(a > 0){
    printf("aは正の数です\n");
  }

  return 0;
}