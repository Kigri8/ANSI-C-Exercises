#include <stdio.h>
int main() {
  char* t = "hello, world";
  char c = 'g';
  char* s = t;
  while (s[0] != '\0') {
    if (s[0] == c) {
      ++s;
      break;
    }
    s++;
  }
  printf("[%s]\n", s);
}