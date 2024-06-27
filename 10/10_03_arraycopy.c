#include <stdio.h>

int main(void)
{
  int heightsCm[5] = {0};
  double heightsMeter[5] = {0.0};

  for (int i = 0; i < 5; i++)
  {
    printf("%d人目の身長? ", i + 1);
    scanf("%d", &heightsCm[i]);
  }

  printf("--- Convert Meter ---\n");

  for (int i = 0; i < 5; i++) heightsMeter[i] = heightsCm[i] / 100.0;

  for (int i = 0; i < 5; i++) printf("%d人目の身長: %f m\n", i + 1, heightsMeter[i]);

  return 0;
}