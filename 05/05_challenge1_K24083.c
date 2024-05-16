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

  if (dayOfWeek == 1 || dayOfWeek == 2 ||  (dayOfWeek == 3 && time == 0) || dayOfWeek ==4 || dayOfWeek == 5 || (dayOfWeek == 6  && time == 1)) {
    printf("診察を行っています\n");
  } else {
    printf("診察は行っていません\n");
  }

  return 0;
}
