#include <stdio.h>

typedef struct elem
{
  int num; // データ部
  struct elem *next;
} Elem;

int main(void)
{
  Elem *root = NULL; // 先頭のポインタを用意
  return 0;
}