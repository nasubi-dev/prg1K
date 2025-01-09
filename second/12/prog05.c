#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem
{
  int num;
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
  Elem *current = root;
  Elem *prev = NULL;
  Elem *new_elem = (Elem *)malloc(sizeof(Elem));
  new_elem->num = num;

  while (current != NULL)
  {
    if (current->num > num)
    {
      break;
    }

    prev = current;
    current = current->next;
  }

  new_elem->next = current; // new_elem の次に current を挿入

  // 空の場合は new_elem が root として返す
  if (prev == NULL)
    return new_elem;

  prev->next = new_elem; // prev の次に new_elem を挿入
  return root;
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

  root = addElem(root, 40);
  root = addElem(root, 20);
  root = addElem(root, 30);
  root = addElem(root, 10);

  printList(root);

  freeList(root);

  return 0;
}