include <stdio.h>
int gcd(int x, int y);
int main() {
  int a = A, b = B;
  printf("%d\n", gcd(a > b ? a : b, b > a ? a : b));
}
int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
return gcd(y, x % y);
}
