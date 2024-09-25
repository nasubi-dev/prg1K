#include <stdio.h>

#define NUM (10)

int main(void)
{
  // 宣言, 変数は必ず初期化を行う
  int sum = 0;
  // 計算
  for (int i = 1; i <= NUM; i++)
    sum += i;
  // 出力
  printf("総和 = %d\n", sum);
  return 0;
}