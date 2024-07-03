#include <stdio.h>
#include "./ai.c"

int playerAction(int board[7][7], int player, int nowGravity, int isAI)
{
  int selectColumnRow = 0;
  char *RowORColumn;

  if (nowGravity % 2 == 0)
    RowORColumn = "Column";
  else
    RowORColumn = "Row";

  if (isAI)
  {
    selectColumnRow = simpleAI(board, nowGravity);
    printf("AI Player %d selects %s: %d\n", player, RowORColumn, selectColumnRow);
  }
  else
  {
    printf("Player %d, enter %s: ", player, RowORColumn);
    scanf("%d", &selectColumnRow);
  }

  // 再帰呼び出し
  if (selectColumnRow < 1 || selectColumnRow > 7 && !isAI)
  {
    printf("Please enter 1~7\n");
    return playerAction(board, player, nowGravity, isAI);
  }

  // 0:↓
  if (nowGravity == 0)
  {
    for (int i = 6; i >= 0; i--)
    {
      if (board[i][selectColumnRow - 1] == 0)
      {
        board[i][selectColumnRow - 1] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 0)
      {
        printf("%s is full\n", RowORColumn);
        return playerAction(board, player, nowGravity, isAI);
      }
    }
  }

  // 1:←
  if (nowGravity == 1)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[selectColumnRow - 1][i] == 0)
      {
        board[selectColumnRow - 1][i] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 6)
      {
        printf("%s is full\n", RowORColumn);
        return playerAction(board, player, nowGravity, isAI);
      }
    }
  }

  // 2:↑
  if (nowGravity == 2)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[i][selectColumnRow - 1] == 0)
      {
        board[i][selectColumnRow - 1] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 6)
      {
        printf("%s is full\n", RowORColumn);
        return playerAction(board, player, nowGravity, isAI);
      }
    }
  }

  // 3:→
  if (nowGravity == 3)
  {
    for (int i = 6; i >= 0; i--)
    {
      if (board[selectColumnRow - 1][i] == 0)
      {
        board[selectColumnRow - 1][i] = player;
        break;
      }
      // 再帰呼び出し
      else if (i == 0)
      {
        printf("%s is full\n", RowORColumn);
        return playerAction(board, player, nowGravity, isAI);
      }
    }
  }

  return 0;
}