#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for a credit card number
    long card = get_long("Number: ");

    // Calculate checksum
    int sum_odd = 0;
    int sum_even = 0;
    long card_sum = card;
    for (int i = 0; i < 16; i++)
    {
        int digit = card_sum % 10;
        if (i%2 != 0)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                sum_even = sum_even + digit % 10 + digit / 10;
            }
            else
            {
                sum_even += digit;
            }
        }
        else
        {
            sum_odd += digit;
        }
        card_sum = card_sum / 10;
    }
    int check_sum = sum_even + sum_odd;

    // Check for card length and starting digits
    int length = 0;
    int starting_digits = 0;
    do
    {
        card = card / 10;
        length ++;
        if (card < 100 && card >9)
        {
            starting_digits = card;
        }
    }
    while (card > 0);

    // Print issuer or invalid
    if (check_sum % 10 == 0)
    {
        if (length == 15 && (starting_digits == 34 || starting_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && starting_digits >= 51 && starting_digits <=55)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && starting_digits / 10 == 4)
        {
            printf("VISA\n");
        }
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
}

