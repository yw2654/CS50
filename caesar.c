#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("one number please\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a 'string' to an 'int'
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i ++)
    {
        // Rotate the chracter if it's a letter
        char ciphertext = rotate(plaintext[i], key);
        printf("%c", ciphertext);
    }
    printf("\n");
    return 0;
}

bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (c - 'A' + n) % 26 + 'A';
    }

    if (c >= 'a' && c <= 'z')
    {
        return (c - 'a' + n) % 26 + 'a';
    }

    else
    {
        return c;
    }
}
