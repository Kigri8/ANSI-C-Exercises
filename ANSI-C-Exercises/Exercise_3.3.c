#include <stdio.h>
#define START 71
#define STOP 18
#define MOD 5
int main() {
  int i = START;
  int count = 0;
  do {
    if (i % MOD == 0) {
      count /= 2;
      continue;
    }
    ++count;
  } while (i-- > STOP);
  printf("%d\n", count);
}