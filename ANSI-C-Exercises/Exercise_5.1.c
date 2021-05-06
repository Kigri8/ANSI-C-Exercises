#include <stdio.h>
int f(int x) {
  return x << 1;
}
void g(int* x) {
  *x *= 2;
}
int main() {
  int a = 3, b = f(a);
  g(&a);
  printf("%d\n", a == b);
}
