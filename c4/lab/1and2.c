#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void calculateHistogram(char fName[], int *arary);
void printValues(const int *array);
void printStars(const int *array);
void encipher(const char *p, char *c, const int offset);
void decipher(const char *c, char *p, const int offset);
double Statistics(int *freq, const double *letFreq);
double LetterFrequencies[26] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0, 2.4, 6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074};
void cipheredTextFreq(char *c, int *Freq);

int main()
{
    int Freq[26] = {};
    // char fileName[] = "employees.txt";
    // int histogramData[26] = {};
    // calculateHistogram(fileName, histogramData);
    char plainText[255] = "This is Nora";
    char cipherText[255];
    int offset = 4;
    int bestScore = 0;
    int character;

    // printValues(histogramData);
    // printStars(histogramData);
    encipher(plainText, cipherText, offset);

    printf("Enciphered Text: %s\n", cipherText);

    for (size_t i = 0; i < 26; i++)
    {
        decipher(cipherText, plainText, i);
        cipheredTextFreq(cipherText, Freq);

        if (Statistics(Freq, LetterFrequencies) > bestScore)
        {
            bestScore = Statistics(Freq, LetterFrequencies);
            offset = i;
        }
    }
    printf("%d\n", offset);
    decipher(cipherText, plainText, offset);

    // decipher(cipherText, plainText, offset);
    printf("Deciphered Text: %s\n", plainText);
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

void printValues(const int *array)
{
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\n", array[i]);
    }
}

void printStars(const int *array)
{
    int size = sizeof(array) / sizeof(array[0]);
    int max = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    for (int j = 0; j < size - 1; j++)
    {
        double proportion = array[j] / max;
        int position = round(proportion * 50);
        for (int k = 0; k < position + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void encipher(const char *p, char *c, const int offset)
{
    int size = strlen(p);
    for (int i = 0; i < size; i++)
    {
        if (isalpha(p[i]))
        {
            if (islower(p[i]))
            {
                c[i] = ((p[i] - 'a' + offset) % 26) + 'a';
            }
            else if (isupper(p[i]))
            {
                c[i] = ((p[i] - 'A' + offset) % 26) + 'A';
            }
        }
        else
        {
            c[i] = p[i];
        }
    }
}

void decipher(const char *c, char *p, const int offset)
{
    int size = strlen(c);
    for (int i = 0; i < size; i++)
    {
        if (isalpha(c[i]))
        {
            if (islower(c[i]))
            {
                p[i] = ((c[i] - 'a' - offset + 26) % 26) + 'a';
            }
            else if (isupper(c[i]))
            {
                p[i] = ((c[i] - 'A' - offset + 26) % 26) + 'A';
            }
        }
        else
        {
            p[i] = c[i];
        }
    }
    p[size] = '\0';
}

double Statistics(int *freq, const double *letFreq)
{

    double score = 0;
    for (size_t i = 0; i < 26; i++)
    {
        score = score + (freq[i] * letFreq[i]);
    }
    return score;
}

void cipheredTextFreq(char *c, int *Freq)
{
    int size = strlen(c);

    for (int i = 0; i < size; i++)
    {
        if (isalpha(c[i]))
        {
            Freq[toupper(c[i]) - 'A']++;
        }
    }
    c[size] = '\0';
}