#include <stdio.h>

int checkGameSet(int board[7][7])
{
  // 横
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1)
      {
        return 1;
      }
      else if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2)
      {
        return 2;
      }
    }
  }

  // 縦
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1)
      {
        return 1;
      }
      else if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2)
      {
        return 2;
      }
    }
  }

  // 斜め
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1)
      {
        return 1;
      }
      else if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2)
      {
        return 2;
      }
    }
  }

  return 0;
}
