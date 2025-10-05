/*
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. 
To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. 
To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: 
translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).
A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. 
This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), 
B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.
A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.
Source: https://cs50.harvard.edu/x/psets/2/substitution/
*/
// substitution.c
// Encrypts a message using a substitution cipher with a user-provided key
// Preserves case and leaves non-alphabetical characters unchanged

#include <cs50.h>     // For get_string and other CS50 libraries
#include <stdio.h>    
#include <stdlib.h>   // For exit codes
#include <string.h>   // For strlen
#include <ctype.h>    // For isalpha, isupper, islower, toupper

// Function to check if key is valid
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext input
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt each character of the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];

        // If it's a letter, substitute it using the key
        if (isalpha(ch))
        {
            int index = toupper(ch) - 'A'; // Find position in alphabet (0–25)

            // Preserve case
            if (isupper(ch))
            {
                printf("%c", toupper(key[index]));
            }
            else
            {
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // Non-alphabetic characters stay the same
            printf("%c", ch);
        }
    }

    // Print newline after ciphertext
    printf("\n");
    return 0;
}

// Function to validate the key
bool is_valid_key(string key)
{
    // Check length
    if (strlen(key) != 26)
    {
        return false;
    }

    // Create an array to track used letters
    bool used[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        char ch = key[i];

        // Key must contain only letters
        if (!isalpha(ch))
        {
            return false;
        }

        int index = toupper(ch) - 'A';

        // Check for duplicate letters
        if (used[index])
        {
            return false;
        }

        used[index] = true;
    }

    return true;
}