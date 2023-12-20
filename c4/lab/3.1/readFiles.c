#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void calculateHistogram(char fName[], int *arary);
void printValues(const int *array, int size);
void printStars(const int *array, int size);
double LetterFrequencies[26] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0, 2.4, 6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074};

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
