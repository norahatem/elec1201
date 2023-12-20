#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char buffer;
    FILE *fPointer = fopen("employees.txt", "r");
    while ((buffer = fgetc(fPointer)) != EOF)
    {
        if (isalpha(buffer))
        {
            printf("%c", toupper(buffer));
        }
    }

    fclose(fPointer);
    return 0;
}