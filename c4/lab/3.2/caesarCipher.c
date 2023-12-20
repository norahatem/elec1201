#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encipher(const char *p, char *c, const int offset);
void decipher(const char *c, char *p, const int offset);

int main()
{
    char plainText[] = "heyy this is nora ";
    char cipherText[strlen(plainText) + 1];
    const int offset = 4;

    printf("Encripted text: ");
    encipher(plainText, cipherText, offset);
    for (int i = 0; cipherText[i] != '\0'; i++)
    {
        printf("%c", cipherText[i]);
    }
    printf("\n");

    printf("Decripted text: ");
    decipher(cipherText, plainText, offset);
    for (int i = 0; plainText[i] != '\0'; i++)
    {
        printf("%c", plainText[i]);
    }
    printf("\n");

    return 0;
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
