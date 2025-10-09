#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool only_alpha(string key);
bool key_length(string key);
bool letter_once(string key);
char rotate(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || argc == 1)
    {
        printf("error\n");
        return 1;
    }

    if (only_alpha(argv[1]) == 0 && key_length(argv[1]) == 0 && letter_once(argv[1]) == 0)
    {
        string plaintext = get_string("plaintext: ");
        rotate (plaintext, argv[1]);
    }
    else
    {
        return 1;
    }
}

bool only_alpha(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("alphabetic only\n");
            return 1;
        }
    }
    return 0;
}

bool key_length(string key)
{
    if (strlen(key) != 26)
    {
        printf("length error\n");
        return 1;
    }
    return 0;
}

bool letter_once(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("more than once\n");
                return 1;
            }
        }
    }
    return 0;
}

char rotate(string plaintext, string key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char ciphertext = 0;
        int k = 0;
        if (isupper(plaintext[i]))
        {
            k = plaintext[i] - 'A';
            ciphertext = toupper(key[k]);
            printf("%c",ciphertext);
        }
        else if (islower(plaintext[i]))
        {
            k = plaintext[i] - 'a';
            ciphertext = tolower(key[k]);
            printf("%c",ciphertext);
        }
        else
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
