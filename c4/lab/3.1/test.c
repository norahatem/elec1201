#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void calculateHistogram(char fName[], int *arary);
void printValues(const int *array, int size);
void printStars(const int *array, int size);

int main()
{
    int histogramData[26] = {};
    char fileName[] = "employees.txt";
    calculateHistogram(fileName, histogramData);
    printValues(histogramData, 26);
    printStars(histogramData, 26);
    return 0;
}

void calculateHistogram(char fName[], int *arary)
{
    int buffer;
    FILE *fptr = fopen(fName, "r");
    while ((buffer = fgetc(fptr)) != EOF)
    {
        if (isalpha(buffer))
        {
            arary[toupper(buffer) - 'A']++;
        }
    }
    fclose(fptr);
}

void printValues(const int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

void printStars(const int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    for (int j = 0; j < size; j++)
    {
        double proportion = (double)array[j] / max;
        int position = round(proportion * 50);
        for (int k = 0; k < position + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
