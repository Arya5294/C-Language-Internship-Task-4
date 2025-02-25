/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

// Function to compress a string using Run-Length Encoding (RLE)
void compressString(const char *input) {
    int count = 1; // Counter for consecutive characters
    char previousChar = input[0]; // Track the first character in the string

    // Loop through the input string starting from the second character
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == previousChar) {
            // Increment the count if the current character matches the previous character
            count++;
        } else {
            // Print the previous character and its count when a new character is encountered
            printf("%c%d", previousChar, count);
            previousChar = input[i]; // Update the previous character
            count = 1; // Reset the count for the new character
        }
    }

    // Print the last set of character and its count
    printf("%c%d\n", previousChar, count);
}

// Function to decompress a string using Run-Length Encoding (RLE)
void decompressString(const char *input) {
    char currentChar; // Variable to store the character being processed
    int count; // Variable to store the count of characters
    int i = 0; // Index for traversing the input string

    // Loop through the input string
    while (input[i] != '\0') {
        currentChar = input[i++]; // Get the character
        count = 0;

        // Extract the count of the character from the input string
        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0'); // Build the number
            i++;
        }

        // Print the character 'count' times
        for (int j = 0; j < count; j++) {
            printf("%c", currentChar);
        }
    }

    // Print a newline after decompression
    printf("\n");
}

// Main function to handle user interaction
int main() {
    int choice; // User's choice from the menu
    char input[1000]; // Buffer to store the input string

    do {
        // Display the menu
        printf("\nRun-Length Encoding (RLE) Tool:\n");
        printf("1. Compress String\n");
        printf("2. Decompress String\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Handle string compression
                printf("Enter the string to compress: ");
                scanf("%s", input); // Read the input string
                printf("Compressed Output: ");
                compressString(input); // Call the compression function
                break;

            case 2:
                // Handle string decompression
                printf("Enter the compressed string to decompress: ");
                scanf("%s", input); // Read the input string
                printf("Decompressed Output: ");
                decompressString(input); // Call the decompression function
                break;

            case 3:
                // Exit the program
                printf("Exiting the program.\n");
                break;

            default:
                // Handle invalid input
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3); // Repeat until the user chooses to exit

    return 0;
}
