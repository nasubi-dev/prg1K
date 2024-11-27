#include <stdio.h>

struct student
{
  char name[64];
  int age;
  char id[10];
  int degree;
};

void printPlace(struct student s)
{
  printf("Name: %s, ", s.name);
  printf("Age: %d, ", s.age);
  printf("ID: %s, ", s.id);
  printf("Degree: %d\n", s.degree);
}

int main(int argc, const char *argv[])
{
  struct student s1 = {"nasubi nasubi", 19, "k24083", 1};
  struct student s2 = {"ninja india", 20, "k24027", 2};
  struct student s3 = {"brain blain", 22, "k24014", 1};
  struct student s4 = {"program fxck", 13, "k24025", 1};

  printPlace(s1);
  printPlace(s2);
  printPlace(s3);
  printPlace(s4);

  return 0;
}