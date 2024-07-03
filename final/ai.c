#include <stdlib.h>
#include <time.h>

// 簡単な AI: ランダムに列を選択
int simpleAI(int board[7][7], int nowGravity) {
    int availableColumns[7];
    int count = 0;
    
    // 利用可能な列を探す
    for (int i = 0; i < 7; i++) {
        if (board[0][i] == 0) {
            availableColumns[count++] = i;
        }
    }
    
    // ランダムに選択
    if (count > 0) {
        int randomIndex = rand() % count;
        return availableColumns[randomIndex] + 1;
    }
    
    // もし利用可能な列がない場合は-1を返す
    return -1;
}

// より高度な AI の実装をここに追加...