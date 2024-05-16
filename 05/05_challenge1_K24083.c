#include <stdio.h>

int main(int argc, const char* argv[]) {
  int dayOfWeek;
  int time;
  int isOpen[7][2] = {
      {0, 0}, {1, 1}, {1, 1}, {1, 0}, {1, 1}, {1, 1}, {0, 1},
  };

  printf("曜日? ");
  scanf("%d", &dayOfWeek);
  printf("時間帯? ");
  scanf("%d", &time);

  if (isOpen[dayOfWeek][time])
    printf("診察を行っています\n");
  else
    printf("診察は行っていません\n");

  return 0;
}
