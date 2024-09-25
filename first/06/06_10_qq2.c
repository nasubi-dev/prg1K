#include <stdio.h>

int main(int argc, const char* argv[])
{
  int n;

  printf("n? ");
  scanf("%d", &n);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 1; j <= 9; j++)
      printf("%d x %d = %d\n", n + i, j, (n + i) * j);
  }
  return 0;
}
