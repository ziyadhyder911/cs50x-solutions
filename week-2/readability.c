/*A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text.
 One such readability test is the Coleman-Liau index. 
 The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. 
 The formula is: index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
Source: https://cs50.harvard.edu/x/psets/2/readability/
*/
// readability.c
// using the Coleman-Liau index formula

#include <cs50.h>     // For get_string and CS50 other libraries
#include <stdio.h>    
#include <string.h>   // For strlen
#include <ctype.h>    // For isalpha, isspace, punctuation checks

int main(void)
{
    // Ask the user to input some text
    string text = get_string("Text: ");

    // Initialize counters for letters, words, and sentences
    int letters = 0;
    int words = 1;         // Start at 1 since the last word won't be followed by a space
    int sentences = 0;

    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Count alphabetic characters as letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Count spaces to estimate number of words
        if (isspace(text[i]))
        {
            words++;
        }

        // Count sentence-ending punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate averages per 100 words
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Apply the Coleman-Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the index to the nearest whole number
    int grade = (int) (index + 0.5);

    // Print the appropriate grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}