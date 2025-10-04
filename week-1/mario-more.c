// Include CS50 library for get_int function
#include <cs50.h>

// Include standard I/O library for printf
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user until they enter a valid height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row from 1 to height
    for (int row = 1; row <= height; row++)
    {
        // Print spaces before the left pyramid
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print left pyramid hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Print fixed gap of two spaces
        printf("  ");

        // Print right pyramid hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}