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

void freeList(Elem *root)
{
  Elem *p = root;
  while (p != NULL)
  {
    Elem *tmp = p->next;
    free(p);
    p = tmp;
  }
}

int main(void)
{
  Elem *root = NULL; // 先頭のポインタを用意

  root = addElem(root, 10);
  root = addElem(root, 4);
  root = addElem(root, 7);
  root = addElem(root, 100);

  printList(root);

  freeList(root);

  return 0;
}