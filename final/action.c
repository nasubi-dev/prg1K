#include <stdio.h>

int playerAction(int board[7][7], int player)
{
  int selectColumn = 0;

  printf("Player %d, enter column: ", player);
  scanf("%d", &selectColumn);

  // 再帰呼び出し
  if (selectColumn > 7 || selectColumn <= 0)
  {
    printf("Invalid column\n");
    return playerAction(board, player);
  }

  for (int i = 6; i >= 0; i--)
  {
    if (board[i][selectColumn - 1] == 0)
    {
      board[i][selectColumn - 1] = player;
      break;
    }
    // 再帰呼び出し
    else if (i == 0)
    {
      printf("Column is full\n");
      return playerAction(board, player);
    }
  }
  return 0;
}