#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rotate(char ct, int k);

int main(int argc, string argv[])
{
    int key, i, ii = 0;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            ii++;
        }
    }
    if (ii != strlen(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plainText = get_string("Plaintext: ");

    key = atoi(argv[1]) % 26;

    printf("Ciphertext: ");

    for (i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            rotate(plainText[i], key);
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
}

void rotate(char plainText, int k)
{
    char c = 0;

    if (isupper(plainText))
    {
        c = (((plainText - 65) + k) % 26) + 65;
        printf("%c", c);
    }
    else if (islower(plainText))
    {
        c = (((plainText - 97) + k) % 26) + 97;
        printf("%c", c);
    }
    else
    {
        printf("%c", plainText);
    }
}
