#include <stdio.h>
#define START 71
#define STOP 18
#define MOD 5
int main() {
  int i = START;
  int count = 0;
  do {
    ++count;
    if (count % MOD == 0) {
      break;
    }
  } while (i-- != STOP);
  printf("%d\n", count);
}