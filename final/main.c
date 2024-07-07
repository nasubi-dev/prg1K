#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MAX_DEPTH 4
#define WIN_SCORE 1000000
#define LOSE_SCORE -1000000

int printNasubi();
int printResult(int isGameFin);
int printTitle();
int printChangeGravity(int nextGravity);

int initGame(int selectGravity, char scanGravity[10]);
int selectPlayerORAI();

int ViewBoard(int board[7][7], int nowGravity);

int changeGravity(int board[7][7], int nextGravity);
int checkGameSet(int board[7][7]);
int playerAction(int board[7][7], int player, int nowGravity, int isAI, int AILavel);

// 簡単な AI: ランダムに列を選択
int simpleAI(int board[7][7], int nowGravity);

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

  // 重力の設定
  selectGravity = initGame(selectGravity, scanGravity);

  srand(time(NULL)); // 乱数の初期化

  ViewBoard(board, nowGravity);
  while (isGameFin == 0)
  {
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

int printNasubi()
{
  printf("                                                              .....(+zztO.     .\n");
  printf("                                                     ..Jztrtrttttrrtrttrt!.(zt\n");
  printf("                                                 ..jrtttrttttrttrttttrtttttttr\n");
  printf("                                            .Jzrtrtrtttrttrtttrttttrttrtttttrt\n");
  printf("                                         .Jtttrtttttrttttrtrtttrttrttttrtrtttr\n");
  printf("                                        .zttttttrtrttrtrttttrtttrtttrtttrtrttt\n");
  printf("                                       .tttrrtrttrttttrttrttrtrttrttrtrttttrtt\n");
  printf("                                 ....J+&zrtttrttttrtrtttrttrtttrtttrtttrttrttr\n");
  printf("                          ...+wuuuuuuuuuuuXwwwwOtttrttrttttttrttttrtttttrtttrt\n");
  printf("                      ..duuuuuuuuuuuuuuuuuuuuuuuXOrttttrtrttrttrtttrtrtttrtttr\n");
  printf("                 ..Juuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuwrtttttrtttrtrtttrtrtttrttt\n");
  printf("              .duuuuuuuuuuuuuqMNuuuzuuzuuzuuuuuuuuuuuwrtrttrtttttrtttttrtttrtt\n");
  printf("           .JuuuuuuuuuuuuuuQMMMM#uuuuuuuuuuzuuzuuzuuuuuttrttrtrttrtrttrttrttrt\n");
  printf("         .wuuuuuuuuuuuuzuuqMMSuMNuuuzuuzuuuuuuuuuuuuuuuOtttttrttrtttrtttrtttrt\n");
  printf("       .wuuuuuuuuuuuuzuuudMMuuuMMKuuuuuuuzuuQgmuuzuuzuuXrtrttttrtttttrtttrtttr\n");
  printf("     .uuuuuuuuuuuuzuuuuuMMBuuuuXM#uuzuuuuQNMM8M#uuuuuuuuXOtrtrtttrtrttrtttI?\n");
  printf("   .uuuuuuuuuuuzuuuuuuzuMBuuuuuuuuuuuzuQMMMuuudMKuuzuuuuuuutttrtttrtttv\n");
  printf("  (uuuuuuzuuzuuuuuuzuuuuuuuzuuzuuzuuuudMBuuuuuuMNuuuzuuuuuVtrttrtO<\n");
  printf(".yuuuuzuuuuuuuzuuzuuuuuuuuuuuuuuuuuzuuuuuzuuzuudM#uuuuzuuuwtOw\n");
  printf("wuuuzuuuuzuuuuuuuuuuzuzuzuuzuuzuuuuuuuzuuuuuuuuuUSuuuuuuuuuuuu\n");
  printf("uuuuuuuuuuzuzuuzuuzuuuuuuuuuuuuzuzuuzuuuzuuzuuuuuuuzuuzuuzuuuu\n");
  printf("uuzuuzuuzuuuuuuuuuuuuzudM#uuzuuuuuuuuuuuuXkuuzuuuuuuuuuuuuuuuu\n");
  printf("uuuuuuuuuuuuuzuuzuuzuuudM#uuuuuuuuzuuzuuuMMuuuuzuzuuzuuzuuzuu\n");
  printf("uuuzuuzuuzuuuuuuuuuuuuzXMNuuuzuzuuuuuuzuqM#uuuuuuuuuuuuuuuuuu\n");
  printf("uuuuuuuuuuuzuuzuuzuuzuuudMNmuuuuuzuuuXgMMBuuuuzuuuzuuzuuzuuu\n");
  printf("uuzuuzuuzuuuuuuuuuuuuuuuuuMMMNNNgNNMMMM8uuuuuuuuzuuuuuuuuuu\n");
  printf("uuuuuuuuuuuuzuuzuuzuuzuuuuuuuXWHHHUUuuuuuuuuzuuuuuuzuuzuuz\n");
  printf("uuzuuzuuzuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuzuuuzuuuuuuuuuu\n");
  printf("uuuuuuuuuzuuzuuzuuzuuzuuzuuzuuuuuuuuuuuzuuuuuuuuzuuzuuuu\n");
  printf("uuzuuzuuuuuuuuuuuuuuuuuuuuuuuuzuuzuuzuuuuuuzuuuuuuuuuu\n");
  printf("uuuuuuzuuuzuuzuuzuuzuuzuuzuuuuuuuuuuuuuuzuuuzuuzuuzu\n");
  printf("uuzuuuuuuzuuuuuuuuuuuuuuuuzuzuuzuuzuuzuuuuuuuuuuu\n");
  printf("uuuuzuuuuuuuzuuzuuzuuzuuuuuuuuuuuuuuuuuzuuzuuzu\n");
  printf("uuuuuuzuuuuuuuuuuuuuuuzuuzuuuzuuzuuzuuuuuuuuu\n");
  printf(" ?wuuuuzuzuuzuuzuuzuuuuuuuuzuuuuuuuuuzuuXV\n");
  printf("   .7XuuuuuuuuuuuuuzuuzuuuuuuuzuuzuV7\n");
  printf("       ?77OXuuzuuuuuuuuzuuzuXV7\n");
  printf("                ~?777-?\n");
  return 0;
}

int printTitle()
{
  printf("\x1b[32m");
  printf("                                 _         __                     \n");
  printf("  ___ ___  _ __  _ __   ___  ___| |_      / _| ___  _ __ ___ ___  \n");
  printf(" / __/ _ \\| '_ \\| '_ \\ / _ \\/ __| __|____| |_ / _ \\| '__/ __/ _ \\ \n");
  printf("| (_| (_) | | | | | | |  __/ (__| ||_____|  _| (_) | | | (_|  __/ \n");
  printf(" \\___\\___/|_| |_|_| |_|\\___|\\___|\\__|    |_|  \\___/|_|  \\___\\___| \n");
  printf("                                                              \n");
  printf("\x1b[39m");
  return 0;
}

int printResult(int isGameFin)
{
  printf("\n\n\n\n\n");
  if (isGameFin == 1)
  {
    printf(" ____  _                       _  __        ___             _  \n");
    printf("|  _ \\| | __ _ _   _  ___ _ __/ | \\ \\      / (_)_ __  ___  | | \n");
    printf("| |_) | |/ _` | | | |/ _ \\ '__| |  \\ \\ /\\ / /| | '_ \\/ __| | | \n");
    printf("|  __/| | (_| | |_| |  __/ |  | |   \\ V  V / | | | | \\__ \\ |_| \n");
    printf("|_|   |_|\\__,_|\\__, |\\___|_|  |_|    \\_/\\_/  |_|_| |_|___/ (_) \n");
    printf("               |___/                                           \n");
  }
  else if (isGameFin == 2)
  {
    printf(" ____  _                      ____   __        ___             _  \n");
    printf("|  _ \\| | __ _ _   _  ___ _ _|___ \\  \\ \\      / (_)_ __  ___  | | \n");
    printf("| |_) | |/ _` | | | |/ _ \\ '__|__) |  \\ \\ /\\ / /| | '_ \\/ __| | | \n");
    printf("|  __/| | (_| | |_| |  __/ |  / __/    \\ V  V / | | | | \\__ \\ |_| \n");
    printf("|_|   |_|\\__,_|\\__, |\\___|_| |_____|    \\_/\\_/  |_|_| |_|___/ (_) \n");
    printf("               |___/                                              \n");
  }
  else if (isGameFin == 3)
  {
    printf("     _                      _  \n");
    printf("  __| |_ __ __ ___      __ | | \n");
    printf(" / _` | '__/ _` \\ \\ /\\ / / | | \n");
    printf("| (_| | | | (_| |\\ V  V /  |_| \n");
    printf(" \\__,_|_|  \\__,_| \\_/\\_/   (_) \n");
    printf("                               \n");
  }
  return 0;
}

int printChangeGravity(int nextGravity)
{
  printf("  ____ _                               ____                 _ _          \n");
  printf(" / ___| |__   __ _ _ __   __ _  ___   / ___|_ __ __ ___   _(_) |_ _   _  \n");
  printf("| |   | '_ \\ / _` | '_ \\ / _` |/ _ \\ | |  _| '__/ _` \\ \\ / / | __| | | | \n");
  printf("| |___| | | | (_| | | | | (_| |  __/ | |_| | | | (_| |\\ V /| | |_| |_| | \n");
  printf(" \\____|_| |_|\\__,_|_| |_|\\__, |\\___|  \\____|_|  \\__,_| \\_/ |_|\\__|\\__, | \n");
  printf("                         |___/                                    |___/  \n");
  return 0;
}

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
    return 1;
  else if (strcmp(yn, "n") == 0)
    return 0;

  printf("Please enter y or n\n");
  return selectPlayerORAI();
}

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

  // 斜め下がり
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

  // 斜め上がり
  for (int i = 0; i < 4; i++)
  {
    for (int j = 3; j < 7; j++)
    {
      if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1)
      {
        return 1;
      }
      else if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2)
      {
        return 2;
      }
    }
  }

  return 0;
}

// 1:↓ 2:← 3:↑ 4:→
// 渡された配列をnowGravityの方向に寄せる
int changeGravity(int board[7][7], int nextGravity)
{
  int index = 0;
  // 0:↓
  if (nextGravity == 0)
  {
    // 列ごとに下に詰める
    for (int i = 0; i < 7; i++)
    {
      for (int j = 6; j >= 0; j--)
      {
        // 0である場合は1or2をその列の中から探し､入れ替える
        if (board[j][i] != 0)
          continue;
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
    selectColumnRow = simpleAI(board, player);
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

int simpleAI(int board[7][7], int nowGravity)
{
  int availableColumns[7];
  int count = 0;

  // 利用可能な列を探す
  for (int i = 0; i < 7; i++)
  {
    if (board[0][i] == 0)
    {
      availableColumns[count++] = i;
    }
  }

  // ランダムに選択
  if (count > 0)
  {
    int randomIndex = rand() % count;
    return availableColumns[randomIndex] + 1;
  }

  // もし利用可能な列がない場合は-1を返す
  return -1;
}
