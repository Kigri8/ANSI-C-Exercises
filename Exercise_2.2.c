#include <stdio.h>
int main()
{
    int x = 100;
    int k = 24;
    int y = (x|1<<k) & ~(1<<k/2);
    printf("%d -> %d \n", x, y);
}
