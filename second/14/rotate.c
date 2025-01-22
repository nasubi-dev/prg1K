#include <stdio.h>
#include <math.h>

unsigned Rrotate(unsigned int x, int n)
{
  unsigned int w = sizeof(unsigned int) << 3;
  unsigned int mask = 0xff;
  return mask & ((x >> n) | (x << (w - n)));
}

unsigned Lrotate(unsigned int x, int n)
{
  unsigned int w = sizeof(unsigned int) << 3;
  unsigned int mask = 0xff;
  return mask & (x << n) | (x >> (w - n));
}

void printbin(unsigned int x)
{
  if (x < 1)
    return;
  printbin(x >> 1);
  printf("%d", x & 1);
}

int main(void)
{
  unsigned int x;

  scanf("%u", &x);
  printbin(x);
  printf("\n");
  printbin(Rrotate(x, 1));
  printf("\n");
  printbin(Lrotate(x, 1));

  return 0;
}