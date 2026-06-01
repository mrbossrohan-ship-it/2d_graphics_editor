#include <stdio.h>

#define ROWS 15
#define COLS 30

char canvas[ROWS][COLS];

// Function 1: Fill the canvas with underscores (Blank slate)
void initializeCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Function 2: Print the 2D array to the terminal
void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

// NEW Function 3: Draw a horizontal line
void drawLine(int row, int colStart, int colEnd) {
    // Loop from the start column to the end column on that specific row
    for (int j = colStart; j <= colEnd; j++) {
        // Safety check to make sure we don't draw outside the canvas grid bounds
        if (row >= 0 && row < ROWS && j >= 0 && j < COLS) {
            canvas[row][j] = '*';
        }
    }
}

// NEW Function 4: Draw a rectangle
void drawRectangle(int startRow, int startCol, int width, int height) {
    int endRow = startRow + height - 1;
    int endCol = startCol + width - 1;

    // Loop through the grid to draw the outer borders of the rectangle
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            // Safety check for boundaries
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                // Only draw a '*' if it's on the edge of the rectangle layout
                if (i == startRow || i == endRow || j == startCol || j == endCol) {
                    canvas[i][j] = '*';
                }
            }
        }
    }
}

int main() {
    printf("--- Day 2: 2D Graphics Editor (Lines & Rectangles) ---\n\n");
    
    // 1. Start with a fresh canvas
    initializeCanvas();
    
    // 2. NEW: Draw a horizontal line on Row 2, from Column 5 to 25
    drawLine(2, 5, 25);
    
    // 3. NEW: Draw a rectangle starting at Row 5, Column 8, Width 12, Height 6
    drawRectangle(5, 8, 12, 6);
    
    // 4. Display the updated canvas
    displayCanvas();
    
    return 0;
}