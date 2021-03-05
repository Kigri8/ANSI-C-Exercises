#include <stdio.h>
#define START 71
#define STOP 18
int main() {
  int i = START;
  int count = 0;
  do {
    ++count;
  } while (i-- != STOP);
  printf("%d\n", count);
}