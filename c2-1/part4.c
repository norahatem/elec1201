#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define PI M_PI

int rand();
const int PLOTWIDTH = 50;

void plotval(float, int);

int main()
{
    unsigned long int x = 0;
    float y;
    float z;
    const int FREQ1 = 10;
    const int FREQ2 = 20;
    float a;
    float b;
    while (1)
    {
        const int NUM_OF_SPACES = 10;
        x++;
        double sine = sin(rand() % 20 * x * (PI / 180));
        double newSine = a + b;
        a = sin((x * (PI / 180)) + rand() % 5);
        b = sin((x * (PI / 180)) + rand() % 10);
        z = (sin(FREQ2 * x * (PI / 180) + 20));
        y = (sin(FREQ1 * x * (PI / 180)) + 1) / 2;
        printf("\x1B[36mx= %.7lu, y=%4.3f | %s ", x, y, x % NUM_OF_SPACES ? "   " : "---");
        plotval(newSine, PLOTWIDTH);
    }
}

void plotval(float sinOutput, int width)
{
    int position = round((width * sinOutput));
    const char SYMBOL = '*';
    printf("\x1B[35m%*c\n\x1B[0m", position + 1, SYMBOL);
}