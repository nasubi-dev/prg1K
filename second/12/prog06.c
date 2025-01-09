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
  Elem *newElem = (Elem *)malloc(sizeof(Elem));
  newElem->num = num;

  while (current != NULL)
  {
    if (current->num > num)
    {
      break;
    }

    prev = current;
    current = current->next;
  }

  newElem->next = current; // new_elem の次に current を挿入

  // 空の場合は new_elem が root として返す
  if (prev == NULL)
    return newElem;

  prev->next = newElem; // prev の次に new_elem を挿入
  return root;
}

Elem *deleteElem(Elem *root, int delnum)
{
  Elem *current = root;
  Elem *prev = NULL;

  while (current != NULL)
  {
    // 削除する要素でない場合
    if (current->num != delnum)
    {
      prev = current;
      current = current->next;
      continue;
    }

    if (prev == NULL)
      root = current->next;
    else
      prev->next = current->next;

    free(current);
    break;
  }

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

  root = addElem(root, 4);
  root = addElem(root, 2);
  root = addElem(root, 1);
  root = addElem(root, 5);
  root = addElem(root, 9);
  root = addElem(root, 100);

  printList(root);

  printf("\n--delete 2--\n");
  deleteElem(root, 2);
  printList(root);

  freeList(root);

  return 0;
}