// Include CS50 library for get_int function
#include <cs50.h>

// Include standard I/O library for printf
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt the user until a valid positive integer is entered
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    // Loop through each row from 1 to height
    for (int row = 1; row <= height; row++)
    {
        // Print spaces to right-align the pyramid
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print hashes for the current row
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }
}