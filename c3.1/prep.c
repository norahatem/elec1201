#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // srand(time(NULL));
    float x;
    int y = rand();
    x = y / 5;
    printf("%d\n", y);
    printf("%f\n", x);
}