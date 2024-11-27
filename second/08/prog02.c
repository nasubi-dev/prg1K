#include <stdio.h>

struct place
{
  double lat;
  double lon;
  char address[64];
};

void printPlace(struct place p)
{
  printf("Latitude: %f, ", p.lat);
  printf("Longitude: %f, ", p.lon);
  printf("Address: %s\n", p.address);
}

int main(int argc, const char *argv[])
{
  struct place p1 = {35.179360, 136.95178, "愛知工業大学名電高等学校"};
  struct place p2 = {35.183400, 137.113095, "愛知工業大学"};

  printPlace(p1);
  printPlace(p2);

  return 0;
}