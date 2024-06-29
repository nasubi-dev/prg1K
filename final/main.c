#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./board.c"
#include "./action.c"
#include "./check.c"
#include "./gravity.c"
#include "./ascii.c"

int initGame(int selectGravity, char scanGravity[10])
{
  printf("\n\n\n");
  printf("Player1: X, Player2: O\n");
  printf("Gravity select 3? 10? random(1~10)?\n");
  scanf("%s", scanGravity);

  if (strcmp(scanGravity, "3") == 0)
    return 3;
  else if (strcmp(scanGravity, "10") == 0)
    return 10;
  else if (strcmp(scanGravity, "random") == 0)
    return rand() % 10 + 1;
  else if (strcmp(scanGravity, "nasubi") == 0)
    printNasubi();

  return initGame(selectGravity, scanGravity);
}

int main(void)
{
  // 0=empty, 1=player1, 2=player2
  int board[7][7] = {0};
  // 0=continue, 1=player1, 2=player2 3=draw
  int isGameFin = 0;
  // nowGravity % 4 + 1 ==> 0: ↓ 1: ← 2: ↑ 3: →
  int nowGravity = 0;
  int move = 1;
  char scanGravity[10];
  int selectGravity = 0;

  printTitle();
  selectGravity = initGame(selectGravity, scanGravity);

  ViewBoard(board, nowGravity);
  while (isGameFin == 0)
  {
    printf("move: %d ", move);

    printf("next change gravity turn : ");

    printf("next gravity: ");
    if ((nowGravity + 1) % 4 == 0)
      printf("↓\n");
    if ((nowGravity + 1) % 4 == 1)
      printf("←\n");
    if ((nowGravity + 1) % 4 == 2)
      printf("↑\n");
    if ((nowGravity + 1) % 4 == 3)
      printf("→\n");

    playerAction(board, move % 2 + 1, nowGravity % 4);
    printf("\n\n\n");
    system("clear");

    ViewBoard(board, nowGravity);

    // 設定した手数ごとに重力を変える
    if (move % selectGravity == 0)
    {
      printChangeGravity((nowGravity + 1) % 4);
      changeGravity(board, (nowGravity + 1) % 4);
      nowGravity++;
      // 再レンダー
      ViewBoard(board, nowGravity);
    }
    isGameFin = checkGameSet(board);

    // 49手目で引き分け(7*7=49)
    if (move == 49)
      isGameFin = 3;
    move++;
  }

  // わかりやすくするためにグラフィカルに表示
  printResult(isGameFin);
  return 0;
}