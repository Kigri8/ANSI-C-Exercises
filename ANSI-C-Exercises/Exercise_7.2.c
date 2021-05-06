#include <stdio.h>
int main() {
  FILE* input = fopen("id.dat", "r");
  char student[8];
  char program[4];
  int grade;
  while (!feof(input)) {
    fscanf(input, "%7s %3s %d\n", student, program, &grade);
    printf("someone from %s got %d\n", program, grade);
  }
  fclose(input);
}