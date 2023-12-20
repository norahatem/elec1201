#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encipher(const char *p, char *c, const int offset);
void decipher(const char *c, char *p, const int offset);
double Statistics(int *freq, const double *letFreq);

double LetterFrequencies[26] = {
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15, 0.77, 4.0,
    2.4, 6.7, 7.5, 1.9, 0.095, 6.0, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2.0, 0.074};

int main()
{
    /* all new functions from part3 use only upper case characters but the enciphers and decipher deals with both upper and lower. chech this later, edit it and see if this works*/
    char plainText[] = "This is Nora";
    char plainText2[sizeof(plainText) / sizeof(plainText[0])] = {};
    char cipherText[sizeof(plainText) / sizeof(plainText[0])];
    int offset = 4;
    int bestScore = 0;
    int Freq[26] = {0};
    encipher(plainText, cipherText, offset);
    printf("Enciphered Text: %s\n", cipherText);

    for (int i = 0; i < 26; i++)
    {
        decipher(cipherText, plainText2, i);

        cipheredTextFreq(cipherText, Freq);
        double score = Statistics(Freq, LetterFrequencies);

        if (score > bestScore)
        {
            // Why does it always enter this if. why is the condition (score> bestscore) always true!
            bestScore = score;
            offset = i;
        }
    }
    printf("Best Offset: %d\n", offset);
    decipher(cipherText, plainText2, offset);
    printf("Deciphered Text: %s\n", plainText2);
    /*
    for i =0;i<26
        decipher
        for (j=0;s=0;plaintext2[j];j++)
         s+= hist
    */

    return 0;
}

void encipher(const char *p, char *c, const int offset)
{
    int size = strlen(p); // used i and j. i for p[i] and j for c[j++]
    for (int i = 0; i < size /*p[i] //is the value of p[i] not equal to zero*/; i++)
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
    c[size] = '\0';
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
    double score = 0.0;
    for (int i = 0; i < 26; i++)
    {
        score = score + (double)(freq[i] * letFreq[i]);
    }
    return score;
}

void cipheredTextFreq(const char *c, int *Freq)
{
    int size = strlen(c);

    for (int i = 0; i < 26; i++)
    {
        Freq[i] = 0;
    }
    for (int j = 0; j < size; j++)
    {
        if (isalpha(c[j]))
        {
            Freq[toupper(c[j]) - 'A']++;
        }
    }
}
