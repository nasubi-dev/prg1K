#include <stdio.h>
#include <string.h>

void swap_str_ptr(char **a, char **b)
{
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort_str_ptr(char **a, char **b)
{
  if (strlen(*a) > strlen(*b))
  {
    swap_str_ptr(a, b);
  }
}

void bubble_str_ptr(char **list, int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      sort_str_ptr(&list[j], &list[j + 1]);
    }
  }
}

int main(void)
{
  char *list[] = {"hoge", "abc", "xy", "fugagaga"};
  int n = sizeof(list) / sizeof(list[0]);

  for (int i = 0; i < n; i++)
  {
    printf("%s\n", list[i]);
  }

  bubble_str_ptr(list, n);
  printf("\nAfter sorting:\n");

  for (int i = 0; i < n; i++)
  {
    printf("%s\n", list[i]);
  }

  return 0;
}