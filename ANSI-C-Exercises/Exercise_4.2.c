#include <stdio.h>
#define TRUE 1
#define FALSE 0
int len(char* s);
int pal(char* t, int s, int e);
int main() {
  char* s = T;
  printf("%s\n", pal(s, 0, len(s) - 1) ? "yes" : "no");
}
int len(char* s) {
  int n = 0;
  while (s[n] != '\0') {
    n++;
  }
  return n;
}
int pal(char *t, int s, int e) {
  if (s >= e) {
    return TRUE;
  }
  if (t[s] == t[e]) {
    return pal(t, ++s, --e);
  }
  return FALSE;
}
