#include <stdio.h>
#include "./board.c"
#include "./action.c"
#include "./check.c"

int main(void)
{
  // タイトル 後でかっこよく
  printf("Connect four + gravity\n");

  // 0=empty, 1=player1, 2=player2
  int board[7][7] = {0};
  // 0=continue, 1=player1, 2=player2
  int isGameFin = 0;
  int move = 1;

  ViewBoard(board);
  while (isGameFin == 0)
  {
    printf("turn %d\n", move);
    playerAction(board, move % 2 + 1);
    ViewBoard(board);
    isGameFin = checkGameSet(board);
    move++;
  }

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