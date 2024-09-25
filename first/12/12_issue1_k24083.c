#include <stdio.h>

int factOf(int n);

int main(void) {
  int n = 0;

  printf("n? ");
  scanf("%d", &n);

  printf("%dの階乗は %d\n", n, factOf(n));

  return 0;
}

int factOf(int n) {
  if (n == 0)
    return 1;
  else
    return n * factOf(n - 1);
}
