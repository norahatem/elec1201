#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define PI M_PI
int main()
{
    unsigned long int x = 0;
    float y;
    const int FREQ = 1;
    while (1)
    {
        x++;
        y = (sin(FREQ * x * (PI / 180)) + 1) / 2;
        printf("x= %.7lu, y=%4.3f\n", x, y);
    }
}