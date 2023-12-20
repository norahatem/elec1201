#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define PI M_PI

const int PLOTWIDTH = 50;

void plotval(float, int);

int main()
{
    unsigned long int x = 0;
    float y;
    const int FREQ = 20;
    while (1)
    {
        const int NUM_OF_SPACES = 10;
        x++;
        y = (sin(FREQ * x * (PI / 180)) + 1) / 2;
        printf("\x1B[0mx= %.7lu, y=%4.3f | %s", x, y, x % NUM_OF_SPACES ? "   " : "---");
        plotval(y, PLOTWIDTH);
    }
}

void plotval(float sinOutput, int width)
{
    int position = round((width * sinOutput));
    const char SYMBOL = '*';
    printf("%*c\n", position + 1, SYMBOL);
}