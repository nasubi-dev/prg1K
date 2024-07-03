#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./board.c"
#include "./action.c"
#include "./check.c"
#include "./gravity.c"
#include "./ascii.c"

int initGame(int selectGravity, char scanGravity[10])
{
  printf("\n");
  printf("Player1: X, Player2: O\n");
  printf("Gravity select 3? 10? random(1~10)?\n");
  scanf("%s", scanGravity);

  if (strcmp(scanGravity, "3") == 0)
    return 3;
  else if (strcmp(scanGravity, "10") == 0)
    return 10;
  else if (strcmp(scanGravity, "random") == 0)
    return rand() % 10 + 1;
  else if (strcmp(scanGravity, "nasubi") == 0)
    printNasubi();

  return initGame(selectGravity, scanGravity);
}

int selectPlayerORAI()
{
  char yn[1];
  printf("Do you want to play against AI? (y/n)");
  scanf("%s", yn);

  if (strcmp(yn, "y") == 0)
  {
    return 1;
  }
  else if (strcmp(yn, "n") == 0)
  {
    return 0;
  }
  printf("Please enter y or n\n");
  return selectPlayerORAI();
}

int selectAILavel()
{
  char lavel[1];
  printf("Select AI lavel 1(random) or 2(AI): ");
  scanf("%s", lavel);

  if (strcmp(lavel, "1") == 0)
  {
    return 1;
  }
  else if (strcmp(lavel, "2") == 0)
  {
    return 2;
  }
  printf("Please enter 0 or 1\n");
  return selectAILavel();
}

int main(void)
{
  // 0=empty, 1=player1, 2=player2
  int board[7][7] = {0};
  // 0=continue, 1=player1, 2=player2 3=draw
  int isGameFin = 0;
  // nowGravity % 4 + 1 ==> 0: ↓ 1: ← 2: ↑ 3: →
  int nowGravity = 0;
  int move = 1;
  char scanGravity[10];
  int selectGravity = 0;
  int playerType[2] = {0, 0};
  int AILavel = 0;

  printTitle();

  // player2をAIにするかどうか
  playerType[1] = selectPlayerORAI();
  if (playerType[1] == 1)
    AILavel = selectAILavel();

  // 重力の設定
  selectGravity = initGame(selectGravity, scanGravity);

  srand(time(NULL)); // 乱数の初期化

  ViewBoard(board, nowGravity);
  while (isGameFin == 0)
  {
    // printf("move: %d ", move);

    printf("next gravity: ");
    if ((nowGravity + 1) % 4 == 0)
      printf("↓\n");
    if ((nowGravity + 1) % 4 == 1)
      printf("←\n");
    if ((nowGravity + 1) % 4 == 2)
      printf("↑\n");
    if ((nowGravity + 1) % 4 == 3)
      printf("→\n");

    printf("next change gravity turn : ");
    if ((move % selectGravity) == 0)
      printf("%d\n", selectGravity);
    else
      printf("%d\n", selectGravity - (move % selectGravity));

    playerAction(board, move % 2 + 1, nowGravity % 4, playerType[move % 2], AILavel);
    printf("\n\n\n");
    system("clear");

    ViewBoard(board, nowGravity);

    // 設定した手数ごとに重力を変える
    if (move % selectGravity == 0)
    {
      printChangeGravity((nowGravity + 1) % 4);
      changeGravity(board, (nowGravity + 1) % 4);
      nowGravity++;
      // 再レンダー
      ViewBoard(board, nowGravity);
    }
    isGameFin = checkGameSet(board);

    // 49手目で引き分け(7*7=49)
    if (move == 49)
      isGameFin = 3;
    move++;
  }

  // わかりやすくするためにグラフィカルに表示
  printResult(isGameFin);
  return 0;
}