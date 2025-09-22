#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user of change owed
    int cents;
    do
    {
        cents = get_int("Change owned: ");
    }
    while (cents < 0);

    // Calculate quarters
    int quarters = cents / 25;
    cents = cents - quarters * 25;

    // Calculate dimes
    int dimes = cents / 10;
    cents = cents - dimes * 10;

    // Calculate nickels
    int nickels = cents / 5;
    cents = cents - nickels * 5;

    // Calculate pennies
    int pennies = cents;

    printf("%i\n", quarters + dimes + nickels + pennies);

}
