#include <stdio.h>      // Includes standard input-output functions like printf and scanf
// #include <conio.h>      // Includes console input-output functions like clrscr() and getch()

// Function for Make Change Problem
void makeChange(int amount) {          // Function definition that takes the amount as input

    int denom[] = {50, 20, 10, 5, 2, 1}; // Array of available denominations (notes/coins)
    int n = 6;                          // Number of denominations in the array
    int i, count;                      // Loop variable and count of notes/coins

    printf("\nCoins/Notes used:\n");    // Display heading

    for (i = 0; i < n; i++) {           // Loop through each denomination
        count = amount / denom[i];     // Calculate how many notes/coins of this denomination are needed
        amount = amount % denom[i];    // Update remaining amount after using the denomination

        if (count != 0) {               // Check if at least one note/coin is used
            printf("%d x %d\n", count, denom[i]); // Print count and denomination
        }
    }
}

// Function for Activity Selection Problem
void activitySelection(int start[], int finish[], int n) { // Function with start times, finish times, and number of activities

    int i, j;                           // Loop variables

    printf("\nSelected activities are:\n"); // Heading for output

    // First activity is always selected
    i = 0;                              // Select the first activity
    printf("(%d, %d)\n", start[i], finish[i]); // Print first selected activity

    // Consider rest of the activities
    for (j = 1; j < n; j++) {            // Loop through remaining activities
        if (start[j] >= finish[i]) {    // Check if activity starts after or when previous ends
            printf("(%d, %d)\n", start[j], finish[j]); // Select and print the activity
            i = j;                      // Update the last selected activity
        }
    }
}

int main() {                            // Main function where execution starts

    clrscr();                           // Clears the console screen (Turbo C specific)

    int choice;                         // Variable to store user's choice

    printf("Choose:\n1. Make Change\n2. Activity Selection\n"); // Menu options
    scanf("%d", &choice);               // Read user choice

    if (choice == 1) {                  // If user chooses Make Change
        int amount;                     // Variable to store amount
        printf("Enter amount: ");       // Ask for amount
        scanf("%d", &amount);           // Read amount
        makeChange(amount);             // Call makeChange function
    }
    else if (choice == 2) {             // If user chooses Activity Selection
        int n, i;                       // Variables for number of activities and loop
        int start[20], finish[20];      // Arrays for start and finish times

        printf("Enter number of activities: "); // Ask for number of activities
        scanf("%d", &n);                // Read number of activities

        printf("Enter start and finish times (sorted by finish time):\n"); // Input instruction
        for (i = 0; i < n; i++) {        // Loop to read start and finish times
            scanf("%d %d", &start[i], &finish[i]); // Read times
        }

        activitySelection(start, finish, n); // Call activity selection function
    }
    else {                              // If invalid choice is entered
        printf("Invalid choice");       // Display error message
    }

    // getch();                            // Wait for a key press (Turbo C specific)
    return 0;                           // End of program
}