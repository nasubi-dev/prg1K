#include <stdio.h>
#define DEBUG_MSG

int main(void)
{
#ifdef DEBUG_MSG
  printf("debug message\n");
#endif

  return 0;
}