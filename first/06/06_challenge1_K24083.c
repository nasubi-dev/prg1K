#include <stdio.h>

int isPrimeNumber(int n)
{
  if (n <= 1)
  {
    return 0;
  }

  int i = 2;
  while (i < n)
  {
    if (n % i == 0)
    {
      return 0;
    }
    i++;
  }

  return 1;
}

int main(int argc, const char *argv[])
{
  int n;

  printf("n? ");
  scanf("%d", &n);

  if (isPrimeNumber(n))
    printf("素数です\n");
  else
    printf("素数ではありません\n");

  return 0;
}
