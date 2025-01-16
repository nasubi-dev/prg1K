#include <stdio.h>

typedef struct melem
{
  char name[64];
  double height;
  double weight;
  struct melem *next;
} Melem;

int main(void) { return 0; }