// Include CS50 library for get_long function
#include <cs50.h>

// Include standard I/O library for printf
#include <stdio.h>

// Include math library for digit extraction
#include <math.h>

int main(void)
{
    // Prompt user for credit card number
    long number = get_long("Number: ");

    // Variables for Luhn's algorithm
    int sum = 0;
    int digit_count = 0;
    long temp = number;

    // Apply Luhn’s algorithm
    while (temp > 0)
    {
        int digit = temp % 10;

        // If it's every other digit starting from the end
        if (digit_count % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10); // Add digits of product
        }

        temp /= 10;
        digit_count++;
    }

    // Check if checksum is valid
    bool is_valid = (sum % 10 == 0);

    // Extract starting digits
    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    // Determine card type
    if (is_valid)
    {
        if ((start == 34 || start == 37) && digit_count == 15)
        {
            printf("AMEX\n");
        }
        else if (start >= 51 && start <= 55 && digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((start / 10 == 4 || start == 4) && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}