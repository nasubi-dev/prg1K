#include <stdio.h>

typedef struct place
{
  double lat;
  double lon;
  char address[100];
} Place;

void print_place(Place p)
{
  printf("緯度: %f\n", p.lat);
  printf("経度: %f\n", p.lon);
  printf("住所: %s\n", p.address);
}

int main()
{
  Place p1 = {35.18378, 137.11355, "愛知県豊田市八草町八千草1247-1"};
  Place p2 = {35.17856, 136.94899, "愛知県名古屋市千種区北千種3丁目4-46"};

  print_place(p1);

  printf("\n");

  print_place(p2);

  return 0;
}