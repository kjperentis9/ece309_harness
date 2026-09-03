#include <stdio.h>   // Allows us to use printf() and fgets().
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