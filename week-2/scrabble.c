// scrabble.c
// CS50-style implementation of a Scrabble-like word scoring game
// Prompts two players for words and determines the winner based on letter scores

#include <cs50.h>     // For get_string and other CS50 libraries
#include <stdio.h>    
#include <ctype.h>    // For isalpha, toupper

// Points assigned to each letter A–Z
// Index 0 = A, 1 = B, ..., 25 = Z
int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
    1, 4, 4, 8, 4, 10
};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Prompt both players for their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Computes and returns the Scrabble score for a given word
int compute_score(string word)
{
    int score = 0;

    // Loop through each character in the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Check if the character is an alphabet letter
        if (isalpha(word[i]))
        {
            // Convert letter to uppercase for consistent indexing
            char uppercase = toupper(word[i]);

            // Calculate index: 'A' = 0, 'B' = 1, ..., 'Z' = 25
            int index = uppercase - 'A';

            // Add corresponding point value to score
            score += POINTS[index];
        }
    }

    return score;
}