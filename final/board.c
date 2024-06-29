#include <stdio.h>

int ViewBoard(int board[7][7], int nowGravity)
{

  // 列番号表示
  if (nowGravity % 2 == 0)
    printf("   \x1b[32m1  2  3  4  5  6  7\x1b[39m\n");
  else
    printf("   1  2  3  4  5  6  7\n");

  for (int i = 0; i < 7; i++)
  {
    // 行番号表示
    if (nowGravity % 2 == 0)
      printf("%d ", i + 1);
    else
      printf("\x1b[32m%d\x1b[39m ", i + 1);

    for (int j = 0; j < 7; j++)
    {
      printf("[");

      if (board[i][j] == 1)
        printf("\x1b[31mX\x1b[39m");
      else if (board[i][j] == 2)
        printf("\x1b[34mO\x1b[39m");
      else
        printf(" ");

      printf("]");
    };
    printf("\n");
  };
  return 0;
};