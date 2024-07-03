#include <stdio.h>
#include "./ai.c"

int playerAction(int board[7][7], int player, int nowGravity, int isAI, int AILavel)
{
  int selectColumnRow = 0;
  char *RowORColumn;

  if (nowGravity % 2 == 0)
    RowORColumn = "Column";
  else
    RowORColumn = "Row";

  if (isAI)
  {
    if (AILavel == 1)
      selectColumnRow = simpleAI(board, player);
    else
      selectColumnRow = advancedAI(board, player, nowGravity);
    printf("AI Player %d selects %s: %d\n", player, RowORColumn, selectColumnRow);
  }
  else
  {
    printf("Player %d, enter %s: ", player, RowORColumn);
    scanf("%d", &selectColumnRow);
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
        return playerAction(board, player, nowGravity, isAI, AILavel);
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
        return playerAction(board, player, nowGravity, isAI, AILavel);
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
        return playerAction(board, player, nowGravity, isAI, AILavel);
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
        return playerAction(board, player, nowGravity, isAI, AILavel);
      }
    }
  }

  return 0;
}