#include <stdio.h>
#define numof(ary) (sizeof ary / sizeof ary[0])

int main(void) {
  int primeNumbers[100] = {};
  int primeNumbersNum = 0;
  int isPrimeNumber = 1;

  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j < primeNumbersNum; j++) {
      if (i % primeNumbers[j] == 0) {
        isPrimeNumber = 0;
        break;
      }
    }

    if (isPrimeNumber == 1) {
      primeNumbers[primeNumbersNum] = i;
      primeNumbersNum++;
    }
    isPrimeNumber = 1;
  }

  for (int i = 0; i < primeNumbersNum; i++) printf("%d, ", primeNumbers[i]);
  printf("\n");

  return 0;
}