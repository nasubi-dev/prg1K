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
  Elem *root = NULL;
  FILE *file;
  char line[256];

  // ファイルを開く
  file = fopen("./second/12/numlist.txt", "r");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    return 1;
  }

  // ファイルから1行ずつ読み込む
  while (fgets(line, sizeof(line), file) != NULL)
  {
    int num = atoi(line);
    root = addElem(root, num);
  }
  fclose(file);

  printList(root);

  freeList(root);

  return 0;
}