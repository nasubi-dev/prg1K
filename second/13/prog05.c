#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct melem
{
  char name[64];
  int height;
  int weight;
  struct melem *next;
} Melem;

void print_melem(Melem *root)
{
  printf("%s %d %d\n", root->name, root->height, root->weight);
  if (root->next != NULL)
    print_melem(root->next);
}

Melem *add_melem(Melem *root, char *name, int height, int weight)
{
  // メモリの確保
  Melem *new = (Melem *)malloc(sizeof(Melem));

  // 文字列のコピー
  strcpy(new->name, name);
  // 変数の定義
  new->height = height;
  new->weight = weight;
  new->next = root;

  // 次の最初になるものを返す
  return new;
}

void free_melem(Melem *root)
{
  if (root->next != NULL)
    free_melem(root->next);
  free(root);
}

int main(void)
{
  Melem *root = NULL;

  root = add_melem(root, "hoge", 170, 60);
  root = add_melem(root, "fuga", 180, 70);
  root = add_melem(root, "piyo", 190, 80);

  print_melem(root);

  free_melem(root);

  return 0;
}