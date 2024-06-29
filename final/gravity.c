#include <stdio.h>

// 1:↓ 2:← 3:↑ 4:→
// 渡された配列をnowGravityの方向に寄せる
int changeGravity(int board[7][7], int nextGravity)
{
  int index = 0;


      printf("Change gravity!!!\n");
      printf("1:↓ 2:← 3:↑ 4:→\n");

  // 0:↓
  if (nextGravity == 0)
  {
    // 列ごとに下に詰める
    for (int i = 0; i < 7; i++)
    {
      for (int j = 6; j >= 0; j--)
      {
        // 0である場合は1or2をその列の中から探し､入れ替える
        if (board[j][i] != 0) continue;
        index = j;
        for (int k = j - 1; k >= 0; k--)
        {
          if (board[k][i] != 0)
          {
            board[index][i] = board[k][i];
            board[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // 1:←
  if (nextGravity == 1)
  {
    // 行ごとに右に詰める
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        // 0である場合は1or2をその列の中から探し､入れ替える
        if (board[i][j] != 0)
          continue;
        index = j;
        for (int k = j + 1; k < 7; k++)
        {
          if (board[i][k] != 0)
          {
            board[i][index] = board[i][k];
            board[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // 2:↑
  if (nextGravity == 2)
  {
    // 列ごとに上に詰める
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        // 0である場合は1or2をその列の中から探し､入れ替える
        if (board[j][i] != 0)
          continue;
        index = j;
        for (int k = j + 1; k < 7; k++)
        {
          if (board[k][i] != 0)
          {
            board[index][i] = board[k][i];
            board[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // 3:→
  if (nextGravity == 3)
  {
    // 行ごとに左に詰める
    for (int i = 0; i < 7; i++)
    {
      for (int j = 6; j >= 0; j--)
      {
        // 0である場合は1or2をその列の中から探し､入れ替える
        if (board[i][j] != 0)
          continue;
        index = j;
        for (int k = j - 1; k >= 0; k--)
        {
          if (board[i][k] != 0)
          {
            board[i][index] = board[i][k];
            board[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  return 0;
}
