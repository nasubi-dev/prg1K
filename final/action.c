#include <stdio.h>

int playerAction(int board[7][7], int player, int nowGravity)
{
  int selectColumn = 0;

  printf("Player %d, enter column: ", player);
  scanf("%d", &selectColumn);

  // 再帰呼び出し
  if (selectColumn > 7 || selectColumn <= 0)
  {
    printf("Invalid column\n");
    return playerAction(board, player, nowGravity);
  }

  // 0:↓
  if (nowGravity == 0)
  {
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
        return playerAction(board, player, nowGravity);
      }
    }
  }

  // 1:←
  if (nowGravity == 1)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[selectColumn - 1][i] == 0)
      {
        board[selectColumn - 1][i] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 6)
      {
        printf("Column is full\n");
        return playerAction(board, player, nowGravity);
      }
    }
  }

  // 2:↑
  if (nowGravity == 2)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[i][selectColumn - 1] == 0)
      {
        board[i][selectColumn - 1] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 6)
      {
        printf("Column is full\n");
        return playerAction(board, player, nowGravity);
      }
    }
  }

  // 3:→
  if (nowGravity == 3)
  {
    for (int i = 6; i >= 0; i--)
    {
      if (board[selectColumn - 1][i] == 0)
      {
        board[selectColumn - 1][i] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 0)
      {
        printf("Column is full\n");
        return playerAction(board, player, nowGravity);
      }
    }
  }

  return 0;
}