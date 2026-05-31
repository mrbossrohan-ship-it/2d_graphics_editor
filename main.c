#include <stdio.h>

// Define the size of our canvas grid
#define ROWS 15
#define COLS 30

// Global 2D array to act as our drawing canvas
char canvas[ROWS][COLS];

// Function 1: Fill the entire canvas with underscores '_' (Blank slate)
void initializeCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Function 2: Print the 2D array to the terminal screen
void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", canvas[i][j]); // Print character followed by a space
        }
        printf("\n"); // Move to the next line after finishing a row
    }
}

int main() {
    printf("--- Day 1: 2D Graphics Editor Canvas ---\n\n");
    
    // 1. Prepare the canvas
    initializeCanvas();
    
    // 2. Display the canvas to the user
    displayCanvas();
    
    return 0;
}