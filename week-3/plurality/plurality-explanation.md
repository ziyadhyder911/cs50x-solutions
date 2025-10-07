# Plurality Election (CS50x Problem Set 3)

This project is my solution for the Plurality problem set from CS50x. The goal was to implement a program that simulates a plurality election, where the candidate with the most votes wins.

---

## 1. Getting Started: The Provided Code

The first step was to get the provided "distribution code" from CS50's staff. It's the starting point, and my task was to fill in the missing functions.

### How to Get the Code

Here's a quick guide on how to get set up in a Linux terminal, such as a CS50 Codespace.

1.  Open your terminal and execute `cd` to go to your home directory.
    ```bash
    cd
    ```
2.  Download the ZIP file containing the code:
    ```bash
    wget [https://cdn.cs50.net/2024/fall/psets/3/plurality.zip](https://cdn.cs50.net/2024/fall/psets/3/plurality.zip)
    ```
3.  Unzip the folder:
    ```bash
    unzip plurality.zip
    ```
4.  Remove the ZIP file as it's no longer needed:
    ```bash
    rm plurality.zip
    # Respond with 'y' when prompted.
    ```
5.  Finally, navigate into the project directory:
    ```bash
    cd plurality
    ```
    At this point, you should see `plurality.c` when you run the `ls` command.

---

## 2. My Approach: Understanding and Completing the TODOs

I completed the problem by analyzing the provided code and filling in the three main functions marked with "TODO."

### The `vote` Function

* **My task:** To update the vote count for a candidate based on a name provided by the user.
* **How I solved it:** I used a `for` loop to go through the array of candidates. Inside the loop, I used `strcmp` to compare the candidate's name from the `string name` input with the names in my `candidates` array. If they matched, I incremented that candidate's vote count by 1 and returned `true`. If the loop finished without finding a match, I returned `false`.

### The `print_winner` Function

* **My task:** To determine and print the winner of the election.
* **How I solved it:** First, I needed to find the maximum number of votes. I used a `for` loop to iterate through all the candidates' vote counts and kept track of the highest number of votes I found. Once I had the highest number, I ran another `for` loop. This time, I checked to see which candidates had a vote count equal to that maximum number. If a candidate's vote count matched the max, I printed their name. This approach handles ties correctly by printing all candidates who have the maximum number of votes.

By completing these functions, I was able to build a working program that correctly counts votes and declares one or more winners. This problem was a great way to practice using arrays of structs and basic logic in C.