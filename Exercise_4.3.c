#include <stdio.h>
#include <math.h>
#define NONE 1
#ifdef NONE
int p(int x, int y) { return x << (y - 1); }
#else
int p(int x, int y) { return (int)pow(x, y); }
#endif
int main() {
  int a = 4, b = 7;
  printf("%d %d\n", p(a, b), p(b, a));
}

