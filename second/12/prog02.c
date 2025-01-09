#include <stdio.h>

typedef struct elem
{
  int num; // データ部
  struct elem *next;
} Elem;

void printList(Elem *root)
{
  Elem *p = root;
  while (p != NULL)
  {
    printf("%d\n", p->num);
    p = p->next;
  }
}

int main(void)
{
  Elem *root = NULL; // 先頭のポインタを用意

  Elem l1 = {10, root};
  root = &l1;
  Elem l2 = {7, root};
  root = &l2;
  Elem l3 = {4, root};
  root = &l3;

  printList(root);

  return 0;
}