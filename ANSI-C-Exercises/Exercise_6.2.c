#include <stdio.h>
#include <stdlib.h>
int comp(const void* x, const void* y) {
  return *(int*)x - *(int*)y;
}
int main(int c, char* v[]) {
  if (c > 1) {
    int i, n = atoi(v[1]);
    int prev = -1;
    int* data = (int*)malloc(1000);
    for (i = 0; i < n; i++) {
      data[i] = rand() % 10;
    }
    qsort(data, n, sizeof(int), comp);
    for (i = 0; i < n; i++) {
      if (data[i] != prev) {
        printf("%d ", data[i]);
        prev = data[i];
      }
    } 
    printf("\n");
    free(data);
  }
}