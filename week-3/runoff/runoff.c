#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximum number of voters and candidates allowed
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] stores the jth ranked candidate index for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidate structure: name, vote count, and elimination status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array to hold all candidates
candidate candidates[MAX_CANDIDATES];

// Global variables to track number of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Ensure proper usage with at least one candidate
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Initialize candidates from command-line arguments
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters from user
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Collect ranked preferences from each voter
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Validate and record the vote
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Runoff loop: repeat until a winner is found
    while (true)
    {
        // Count votes for non-eliminated candidates
        tabulate();

        // Check if a candidate has won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Find the minimum vote count among remaining candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, print all remaining candidates as winners
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate candidate(s) with the minimum vote count
        eliminate(min);

        // Reset vote counts for next round
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record a voter's preference if the candidate name is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; // Store candidate index
            return true;
        }
    }
    return false; // Invalid candidate name
}

// Count one vote for each voter's highest-ranked non-eliminated candidate
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break; // Stop after counting one valid vote
            }
        }
    }
    return;
}

// Check if any candidate has more than half the votes
bool print_winner(void)
{
    int majority = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false; // No winner yet
}

// Find the smallest vote count among non-eliminated candidates
int find_min(void)
{
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Check if all non-eliminated candidates are tied
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false; // Found a candidate with different vote count
        }
    }
    return true; // All remaining candidates have same vote count
}

// Eliminate all candidates with the minimum vote count
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}