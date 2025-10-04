// Include the CS50 library for get_string function
#include <cs50.h>

// Include the standard I/O library for printf function
#include <stdio.h>

int main(void)
{
    // Prompt the user to enter their name
    string name = get_string("What's your name? ");

    // Greet the user using their name
    printf("hello, %s\n", name);
}