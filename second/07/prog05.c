#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  int n;

  printf("n? ");
  scanf("%d", &n);

  if ((p = (int *)malloc(n * sizeof(int))) == NULL) {
    printf("No enough memory.\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }

  for (int i = n - 1; i >= 0; i--) {
    printf("%d\n", p[i]);
  }

  free(p);

  return 0;
}