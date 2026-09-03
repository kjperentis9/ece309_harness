"I need to write a simple command-line program in C. I am a beginner, so please keep the code as simple as possible. Do not use external libraries, only standard ones like <stdio.h> and <string.h>. Here is the specification for the program: 1. It should run an infinite while loop that asks for user input using fgets. 2. If the user types 'exit', the loop should break and the program should end. 3. If the user types a sentence containing the word 'hello', the program should print a hardcoded greeting. 4. If the user types anything else, it should echo their input back to them. 5. Please add clear, line-by-line comments explaining what the code is doing."

"#include <stdio.h>   // Allows us to use printf() and fgets().
#include <string.h>  // Allows us to use strcmp(), strstr(), and strcspn().

int main(void) {
    char input[200];  // Creates space to store up to 199 characters of user input.

    while (1) {  // Starts an infinite loop.
        printf("Enter something: ");  // Asks the user to enter text.

        // Reads one line of input and stores it in the input array.
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // Ends the loop if the input cannot be read.
        }

        // Finds the newline character added by fgets() and replaces it with '\0'.
        input[strcspn(input, "\n")] = '\0';

        // Checks whether the user's entire input is exactly "exit".
        if (strcmp(input, "exit") == 0) {
            break;  // Ends the loop.
        }

        // Checks whether the user's input contains "hello".
        if (strstr(input, "hello") != NULL) {
            printf("Hello! It is nice to meet you.\n");  // Prints a greeting.
        } else {
            printf("You entered: %s\n", input);  // Echoes any other input.
        }
    }

    printf("Program ended.\n");  // Lets the user know the program is finished.

    return 0;  // Indicates that the program ended successfully.
}

This version is case-sensitive, so it recognizes hello, but not Hello or HELLO. "

" Write a very simple Bash script (for Linux/Mac) that automatically sends the word 'hello', followed by the word 'exit', into the program to test if it works"

"Assuming the C program is compiled as program:

#!/bin/bash

# Send "hello" and then "exit" to the program.
printf "hello\nexit\n" | ./program"
