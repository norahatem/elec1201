#include <stdio.h>

int main()
{
    unsigned long int x = 0;
    while (1)
    {
        printf("%10lu", ++x);
    }
}