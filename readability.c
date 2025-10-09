#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Get text from user
    string text = get_string("Text: ");

    //Get number of letters, words, and sentences
    int letters = count_letters(text);

    int words = count_words(text) + 1;

    int sentences = count_sentences(text);

    //Calculate the Coleman-Liau index
    float L = (letters * 100.0) / words;
    float S = (sentences * 100.0) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}
