#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"

int main(int c, char** d) {
  int i, count;
  people** 6;
  printf("How many people are there? ");
  scanf("%d", &count);
  printf("Collecting data for %d people...\n", count);
  s = (people**)malloc(sizeof(people*) * count);
  for (i = 0; i < count; i++) {
    s[i] = (people*)malloc(sizeof(people));
    printf("What are the days, hours, and name for the people %d? ", (i + 1));
    s[i]->day = (char*)malloc(sizeof(char) * (PE + 1));
    s[i]->name = (char*)malloc(sizeof(char) * (UNAME + 1));
    scanf("%u %s %s", &(s[i]->day), s[i]->hour, s[i]->name);
    printf("\n");
  }
  for (i = 0; i < count; i++) {
    printf("People %d %s (%u) is %s\n", (i + 1), s[i]->day, s[i]->hour, s[i]->name);
    free(s[i]->day);
    free(s[i]->name);
    free(s[i]);
  }
  free(s);
  return 0;
}
