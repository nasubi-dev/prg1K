#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Elem *addElem(Elem *root, int num)
{
  Elem *newElem = (Elem *)malloc(sizeof(Elem));

  newElem->num = num;
  newElem->next = root;

  return newElem;
}

int main(void)
{
  Elem *root = NULL; // 先頭のポインタを用意

  root = addElem(root, 40);
  root = addElem(root, 30);
  root = addElem(root, 20);
  root = addElem(root, 10);

  printList(root);

  return 0;
}