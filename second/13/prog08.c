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
  Melem *next = root;
  Melem *prev = NULL;

  // ここでprevとnextを決める。
  while (next != NULL)
  {
    if (strcmp(next->name, name) >= 0)
      break;
    prev = next;
    next = next->next;
  }

  if (next != NULL && strcmp(next->name, name) == 0)
  {
    next->height = height;
    next->weight = weight;
    return root;
  }

  Melem *new = (Melem *)malloc(sizeof(Melem));
  strcpy(new->name, name);
  new->height = height;
  new->weight = weight;

  new->next = next;

  if (prev == NULL)
    return new;

  prev->next = new;
  return root;
}

Melem *delete_melem(Melem *root, char *name)
{
  Melem *next = root;
  Melem *prev = NULL;

  while (next != NULL)
  {
    if (strcmp(next->name, name) == 0)
      break;
    prev = next;
    next = next->next;
  }

  if (next == NULL)
    return root;

  if (prev == NULL)
  {
    root = next->next;
  }
  else
  {
    prev->next = next->next;
  }

  free(next);
  return root;
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

  root = add_melem(root, "bbb", 180, 70);
  root = add_melem(root, "aaa", 170, 60);
  root = add_melem(root, "ccc", 190, 80);
  root = add_melem(root, "aaa", 200, 100);
  root = delete_melem(root, "aaa");

  print_melem(root);

  free_melem(root);

  return 0;
}