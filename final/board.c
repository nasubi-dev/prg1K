#include <stdio.h>

int ViewBoard(int board[7][7])
{
  // 列番号表示
  printf("   1  2  3  4  5  6  7\n");

  for (int i = 0; i < 7; i++)
  {
    // 行番号表示
    printf("%d ", i + 1);

    for (int j = 0; j < 7; j++)
    {
      printf("[");

      if (board[i][j] == 1) printf("X");
      else if (board[i][j] == 2) printf("O");
      else printf(" ");

      printf("]");
    };
    printf("\n");
  };
  return 0;
};