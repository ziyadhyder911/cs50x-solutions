// Include CS50 library for get_int function
#include <cs50.h>

// Include standard I/O library for printf
#include <stdio.h>

int main(void)
{
    int cents;

    // Prompt the user until they enter a non-negative integer
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Initialize coin counter
    int coins = 0;

    // Count quarters (25¢)
    coins += cents / 25;
    cents %= 25;

    // Count dimes (10¢)
    coins += cents / 10;
    cents %= 10;

    // Count nickels (5¢)
    coins += cents / 5;
    cents %= 5;

    // Count pennies (1¢)
    coins += cents;

    // Print the total number of coins
    printf("%d\n", coins);
}