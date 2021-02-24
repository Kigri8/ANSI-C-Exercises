#include <stdio.h>
int main() {
  float x = 1.769;
  int y = 20;
  while (x <= y) {
    x = x / 5;
    y = y * x;
  }
  printf("%.2f, %d\n", x, y);
}
