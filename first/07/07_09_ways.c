#include <stdio.h>

int main(void) {
  int n = 0;
  int x = 0;
  int count = 0;

  printf("n x? ");
  scanf("%d %d", &n, &x);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i + j + k == x) {
          printf("%d%d%d\n", i, j, k);
          count += 1;
        }
      }
    }
  }

  printf("組み合わせの数: %d\n", count);
  return 0;
}
