#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_DEPTH 4
#define WIN_SCORE 1000000
#define LOSE_SCORE -1000000

// 簡単な AI: ランダムに列を選択
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

// より高度な AI の実装をここに追加...

// 4つの連続する位置の評価
int evaluateWindow(int playerCount, int opponentCount)
{
  if (playerCount == 4)
    return WIN_SCORE;
  if (opponentCount == 4)
    return LOSE_SCORE;
  if (playerCount == 3 && opponentCount == 0)
    return 100;
  if (playerCount == 2 && opponentCount == 0)
    return 10;
  if (opponentCount == 3 && playerCount == 0)
    return -100;
  if (opponentCount == 2 && playerCount == 0)
    return -10;
  return 0;
}

// 盤面の評価関数
int evaluateBoard(int board[7][7], int player)
{
  int score = 0;
  int opponent = (player == 1) ? 2 : 1;

  // 横、縦、斜めの評価
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      // 横の評価
      if (j <= 3)
      {
        int playerCount = 0, opponentCount = 0;
        for (int k = 0; k < 4; k++)
        {
          if (board[i][j + k] == player)
            playerCount++;
          if (board[i][j + k] == opponent)
            opponentCount++;
        }
        score += evaluateWindow(playerCount, opponentCount);
      }

      // 縦の評価
      if (i <= 3)
      {
        int playerCount = 0, opponentCount = 0;
        for (int k = 0; k < 4; k++)
        {
          if (board[i + k][j] == player)
            playerCount++;
          if (board[i + k][j] == opponent)
            opponentCount++;
        }
        score += evaluateWindow(playerCount, opponentCount);
      }

      // 右下がりの斜めの評価
      if (i <= 3 && j <= 3)
      {
        int playerCount = 0, opponentCount = 0;
        for (int k = 0; k < 4; k++)
        {
          if (board[i + k][j + k] == player)
            playerCount++;
          if (board[i + k][j + k] == opponent)
            opponentCount++;
        }
        score += evaluateWindow(playerCount, opponentCount);
      }

      // 左下がりの斜めの評価
      if (i <= 3 && j >= 3)
      {
        int playerCount = 0, opponentCount = 0;
        for (int k = 0; k < 4; k++)
        {
          if (board[i + k][j - k] == player)
            playerCount++;
          if (board[i + k][j - k] == opponent)
            opponentCount++;
        }
        score += evaluateWindow(playerCount, opponentCount);
      }
    }
  }

  return score;
}

// 指定された列に駒を配置する関数（既存の playerAction 関数から抽出）
void makeMove(int board[7][7], int col, int player, int nowGravity)
{
  if (nowGravity == 0)
  {
    for (int i = 6; i >= 0; i--)
    {
      if (board[i][col] == 0)
      {
        board[i][col] = player;
        break;
      }
    }
  }
  else if (nowGravity == 1)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[col][i] == 0)
      {
        board[col][i] = player;
        break;
      }
    }
  }
  else if (nowGravity == 2)
  {
    for (int i = 0; i < 7; i++)
    {
      if (board[i][col] == 0)
      {
        board[i][col] = player;
        break;
      }
    }
  }
  else if (nowGravity == 3)
  {
    for (int i = 6; i >= 0; i--)
    {
      if (board[col][i] == 0)
      {
        board[col][i] = player;
        break;
      }
    }
  }
}


int checkGameSetAI(int board[7][7])
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

// ミニマックスアルゴリズム（アルファベータ枝刈り付き）
int minimax(int board[7][7], int depth, int alpha, int beta, int maximizingPlayer, int player, int nowGravity)
{
  int gameState = checkGameSetAI(board);
  if (gameState == player)
    return WIN_SCORE;
  if (gameState == 3 - player)
    return LOSE_SCORE;
  if (gameState == 3 || depth == 0)
    return evaluateBoard(board, player);

  if (maximizingPlayer)
  {
    int maxEval = INT_MIN;
    for (int col = 0; col < 7; col++)
    {
      if (board[0][col] == 0)
      {
        int tempBoard[7][7];
        memcpy(tempBoard, board, sizeof(int) * 7 * 7);
        makeMove(tempBoard, col, player, nowGravity);
        int eval = minimax(tempBoard, depth - 1, alpha, beta, 0, player, (nowGravity + 1) % 4);
        maxEval = (eval > maxEval) ? eval : maxEval;
        alpha = (alpha > eval) ? alpha : eval;
        if (beta <= alpha)
          break;
      }
    }
    return maxEval;
  }
  else
  {
    int minEval = INT_MAX;
    for (int col = 0; col < 7; col++)
    {
      if (board[0][col] == 0)
      {
        int tempBoard[7][7];
        memcpy(tempBoard, board, sizeof(int) * 7 * 7);
        makeMove(tempBoard, col, 3 - player, nowGravity);
        int eval = minimax(tempBoard, depth - 1, alpha, beta, 1, player, (nowGravity + 1) % 4);
        minEval = (eval < minEval) ? eval : minEval;
        beta = (beta < eval) ? beta : eval;
        if (beta <= alpha)
          break;
      }
    }
    return minEval;
  }
}

// 最善の手を選択
int getBestMove(int board[7][7], int player, int nowGravity)
{
  int bestScore = INT_MIN;
  int bestMove = -1;

  for (int col = 0; col < 7; col++)
  {
    if (board[0][col] == 0)
    {
      int tempBoard[7][7];
      memcpy(tempBoard, board, sizeof(int) * 7 * 7);
      makeMove(tempBoard, col, player, nowGravity);
      int score = minimax(tempBoard, MAX_DEPTH, INT_MIN, INT_MAX, 0, player, (nowGravity + 1) % 4);
      if (score > bestScore)
      {
        bestScore = score;
        bestMove = col;
      }
    }
  }

  return bestMove + 1; // 1-based index for user input
}

// AIプレイヤーの行動を決定
int advancedAI(int board[7][7], int player, int nowGravity)
{
  return getBestMove(board, player, nowGravity);
}