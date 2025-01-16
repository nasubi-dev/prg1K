#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct melem {
  char name[64];
  int height;
  int weight;
  struct melem *next;
} Melem;

void print_melem(Melem *root) {
  if (root == NULL) return;
  printf("%s %d %d\n", root->name, root->height, root->weight);
  if (root->next != NULL) print_melem(root->next);
}

Melem *add_melem(Melem *root, char *name, int height, int weight) {
  Melem *next = root;
  Melem *prev = NULL;

  // ここでprevとnextを決める。
  while (next != NULL) {
    if (strcmp(next->name, name) >= 0) break;
    prev = next;
    next = next->next;
  }

  if (next != NULL && strcmp(next->name, name) == 0) {
    next->height = height;
    next->weight = weight;
    return root;
  }

  Melem *new = (Melem *)malloc(sizeof(Melem));
  strcpy(new->name, name);
  new->height = height;
  new->weight = weight;

  new->next = next;

  if (prev == NULL) return new;

  prev->next = new;
  return root;
}

Melem *delete_melem(Melem *root, char *name) {
  Melem *next = root;
  Melem *prev = NULL;

  while (next != NULL) {
    if (strcmp(next->name, name) == 0) break;
    prev = next;
    next = next->next;
  }

  if (next == NULL) return root;

  if (prev == NULL) {
    root = next->next;
  } else {
    prev->next = next->next;
  }

  free(next);
  return root;
}

void free_melem(Melem *root) {
  if (root->next != NULL) free_melem(root->next);
  free(root);
}

Melem *execCmdLoop(Melem *root) {
  char input[128];
  char *cmd;
  char name[64];
  int height, weight;

  printf("a: 追加, d: 削除, p: 表示, q: 終了\n");

  do {
    // 改行までを取得
    printf("cmd: ");
    scanf("%[^\n]", input);

    // 先頭の文字を取得
    cmd = strtok(input, " ");

    switch (*cmd) {
      case 'a':
        strcpy(name, strtok(NULL, ","));
        height = atoi(strtok(NULL, ","));
        weight = atoi(strtok(NULL, ","));
        root = add_melem(root, name, height, weight);
        break;
      case 'd':
        strcpy(name, strtok(NULL, ""));
        root = delete_melem(root, name);
        break;
      case 'p':
        print_melem(root);
        break;
      case 'q':
        break;
    }
    getchar();
  } while (*cmd != 'q');

  return root;
}

Melem *readFile(Melem *root, char *filename) {
  FILE *file;
  char line[256];

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("ファイルを開けませんでした。\n");
    return root;
  }

  char name[64];
  int height, weight;
  // ファイルから1行ずつ読み込む
  while (fgets(line, sizeof(line), file) != NULL) {
    strcpy(name, strtok(line, ","));
    height = atoi(strtok(NULL, ","));
    weight = atoi(strtok(NULL, ","));
    root = add_melem(root, name, height, weight);
  }
  fclose(file);

  return root;
}

void writeFile(Melem *root, char *filename) {
  FILE *file;

  file = fopen(filename, "w");
  if (file == NULL) {
    printf("ファイルを開けませんでした。\n");
    return;
  }

  Melem *p = root;
  while (p != NULL) {
    fprintf(file, "%s,%d,%d\n", p->name, p->height, p->weight);
    p = p->next;
  }

  fclose(file);
}

int main(void) {
  Melem *root = NULL;

  root = readFile(root, "./second/13/meibo.csv");
  root = execCmdLoop(root);
  writeFile(root, "./second/13/meibo.csv");

  free_melem(root);

  return 0;
}