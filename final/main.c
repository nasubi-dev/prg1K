#include <stdio.h>
#include "./board.c"
#include "./action.c"
#include "./check.c"
#include "./gravity.c"

int main(void)
{
  // 0=empty, 1=player1, 2=player2
  int board[7][7] = {0};
  // 0=continue, 1=player1, 2=player2 3=draw
  int isGameFin = 0;
  // 1:↓ 2:← 3:↑ 4:→
  int nowGravity = 1;
  int move = 1;

  // タイトル 後でかっこよく
  printf("Connect four + gravity\n");
  // printf("Start game? [y/N]\n");

  ViewBoard(board);
  while (isGameFin == 0)
  {
    printf("move: %d ", move);
    printf("next gravity: %d\n", nowGravity);

    playerAction(board, move % 2 + 1);
    printf("\n\n\n");

    ViewBoard(board);
    //! test 3手目で重力変更
    if (move % 3 == 0)
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
  printf("\n\n\n\n\n");
  printf("Game set Winner: %d\n", isGameFin);
  if (isGameFin == 1)
  {
    printf("Player 1 win\n");
  }
  else if (isGameFin == 2)
  {
    printf("Player 2 win\n");
  }

  return 0;
};