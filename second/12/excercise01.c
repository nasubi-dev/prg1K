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

  // --- ファイルから読み込む ---

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

  // --- ユーザからの入力を受け付ける ---

  char input[16];
  char *cmd;

  printf("a: 追加, d: 削除, p: 表示, q: 終了\n");

  do
  {
    // 改行までを取得
    printf("cmd: ");
    scanf("%[^\n]", input);

    // 先頭の文字を取得
    cmd = strtok(input, " ");

    char *str_n = strtok(NULL, " ");
    int n;
    if (str_n != NULL)
      n = atoi(str_n);

    switch (*cmd)
    {
    case 'a':
      root = addElem(root, n);
      break;
    case 'd':
      root = deleteElem(root, n);
      break;
    case 'p':
      printList(root);
      break;
    case 'q':
      break;
    }
    getchar(); // 改行を読み飛ばす
  } while (*cmd != 'q');

  // --- ファイルに書き込む ---

  file = fopen("./second/12/numlist.txt", "w");
  if (file == NULL)
  {
    printf("ファイルを開けませんでした。\n");
    return 1;
  }

  Elem *p = root;
  while (p != NULL)
  {
    fprintf(file, "%d\n", p->num);
    p = p->next;
  }

  freeList(root);

  return 0;
}