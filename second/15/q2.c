#include <stdio.h>
#include <stdlib.h>

typedef struct Trial
{
  int speed;
  int distance;
} Trial;

// 期待する回答 speed: 10,distance :18
void dispTrial(Trial *trial)
{
  printf("speed: %d,distance: %d\n", trial->speed, trial->distance);
}

int main(void)
{
  Trial *trial = (Trial *)malloc(sizeof(Trial));

  char line[] = "10,18\n";

  sscanf(line, "%d,%d", &trial->speed, &trial->distance);

  // 期待する回答 speed: 10,distance :18
  dispTrial(trial);

  return 0;
}