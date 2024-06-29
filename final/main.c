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
  printf("Player1: X, Player2: O\n");
  printf("Gravity select 3? 10? random?\n");
  scanf("%s", scanGravity);

  if (strcmp(scanGravity, "3") == 0)
  {
    selectGravity = 3;
    return 0;
  }
  else if (strcmp(scanGravity, "10") == 0)
  {
    selectGravity = 10;
    return 0;
  }
  else if (strcmp(scanGravity, "random") == 0)
  {
    selectGravity = rand() % 4 + 1;
    return 0;
  }
  else if (strcmp(scanGravity, "nasubi") == 0)
  {
    printNasubi();
    return initGame(selectGravity, scanGravity);
  }
  return initGame(selectGravity, scanGravity);
}

int main(void)
{
  // 0=empty, 1=player1, 2=player2
  int board[7][7] = {0};
  // 0=continue, 1=player1, 2=player2 3=draw
  int isGameFin = 0;
  // nowGravity % 4 + 1 ==> 1: ↓ 2: ← 3: ↑ 4: →
  int nowGravity = 1;
  int move = 1;
  char scanGravity[10];
  int selectGravity = 0;

  printTitle();
  initGame(selectGravity, scanGravity);

  ViewBoard(board);
  while (isGameFin == 0)
  {
    printf("move: %d ", move);
    printf("next gravity: ");
    if (nowGravity % 4 == 1)
      printf("↓\n");

    playerAction(board, move % 2 + 1, nowGravity);
    printf("\n\n\n");

    ViewBoard(board);
    //! test 3手目で重力変更
    if (move % selectGravity == 0)
    {

      changeGravity(board, nowGravity % 4 + 1);
      nowGravity++;
      ViewBoard(board);
    }
    isGameFin = checkGameSet(board);

    // 49手目で引き分け
    if (move == 49)
      isGameFin = 3;
    move++;
  }

  // わかりやすくするためにグラフィカルに表示
  printResult(isGameFin);
  return 0;
}