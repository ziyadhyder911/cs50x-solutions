/*
Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by 𝑘 positions.
 More formally, if 𝑝 is some plaintext (i.e., an unencrypted message), 
 𝑝𝑖 is the 𝑖𝑡⁢ℎ character in 𝑝, and 𝑘 is a secret key (i.e., a non-negative integer), then each letter, 𝑐𝑖, in the ciphertext, 
 𝑐, is computed as: 𝑐𝑖=(𝑝𝑖+𝑘) % 26
wherein % 26 here means “remainder when dividing by 26.”
Source: https://cs50.harvard.edu/x/psets/2/caesar/
*/
// caesar.c
// Preserves case and leaves non-alphabetical characters unchanged

#include <cs50.h>     // For get_string and other CS50 libraries
#include <stdio.h>    
#include <stdlib.h>   // For atoi
#include <ctype.h>    // For isalpha, isupper, islower

int main(int argc, string argv[])
{
    // Check if the user provided exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Loop through each character in the key to make sure it's a digit
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key from string to integer
    int key = atoi(argv[1]);

    // Prompt the user for plaintext input
    string plaintext = get_string("plaintext:  ");

    // Print the label for ciphertext
    printf("ciphertext: ");

    // Loop through each character in the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];

        // If the character is a letter, apply the cipher
        if (isalpha(ch))
        {
            // Preserve case by checking if it's uppercase or lowercase
            char base = isupper(ch) ? 'A' : 'a';

            // Rotate the character by key positions and wrap around using modulo
            char encrypted = (ch - base + key) % 26 + base;

            // Print the encrypted character
            printf("%c", encrypted);
        }
        else
        {
            // If it's not a letter, print it as-is
            printf("%c", ch);
        }
    }

    // Print a newline after the ciphertext
    printf("\n");

    // Exit successfully
    return 0;
}