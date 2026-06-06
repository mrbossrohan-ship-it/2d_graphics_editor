#include <stdio.h>
#include <math.h>

int main() {
    
    char canvas[15][30];
    int choice = 0;

    
    int r, c, length, width, height, radius;
    int sr, sc; // start row, start col

    // for canvas initlzn
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 30; j++) {
            canvas[i][j] = '_';
        }
    }

    // instead of while(1)
    while (choice != 5) {
        
        // canvas print
        printf("\nCanvas\n");
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 30; j++) {
                printf("%c ", canvas[i][j]);
            }
            printf("\n");
        }

        
        printf("\n--- 2D Graphics Editor Menu ---\n");
        printf("1. Add a Horizontal Line\n");
        printf("2. Add a Rectangle\n");
        printf("3. Add a Circle\n");
        printf("4. Delete/Clear Entire Canvas\n");
        printf("5. Save & Exit Program\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        
        if (choice == 1) {
            // Draw Line
            printf("Enter row number (0-14): ");
            scanf("%d", &r);
            printf("Enter starting column (0-29): ");
            scanf("%d", &sc);
            printf("Enter line length: ");
            scanf("%d", &length);

            for (int j = sc; j < sc + length; j++) {
                if (r >= 0 && r < 15 && j >= 0 && j < 30) {
                    canvas[r][j] = '.'; 
                }
            }
        } 
        else if (choice == 2) {
            // Draw Rectangle
            printf("Enter starting row (0-14): ");
            scanf("%d", &sr);
            printf("Enter starting column (0-29): ");
            scanf("%d", &sc);
            printf("Enter width: ");
            scanf("%d", &width);
            printf("Enter height: ");
            scanf("%d", &height);

            int er = sr + height - 1;
            int ec = sc + width - 1;

            for (int i = sr; i <= er; i++) {
                for (int j = sc; j <= ec; j++) {
                    if (i >= 0 && i < 15 && j >= 0 && j < 30) {
                        if (i == sr || i == er || j == sc || j == ec) {
                            canvas[i][j] = '.'; 
                        }
                    }
                }
            }
        } 
        else if (choice == 3) {
            // Draw Circle
            printf("Enter center row (0-14): ");
            scanf("%d", &r);
            printf("Enter center column (0-29): ");
            scanf("%d", &c);
            printf("Enter radius: ");
            scanf("%d", &radius);

            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 30; j++) {
                    double dist = pow(i - r, 2) + pow(j - c, 2);
                    double rad_sq = pow(radius, 2);
                    if (fabs(dist - rad_sq) < 1.5) {
                        canvas[i][j] = '.'; // Add star
                    }
                }
            }
        } 
        else if (choice == 4) {
            // Delete / Clear Objects
            // We modify the picture by turning all stars back into underscores!
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 30; j++) {
                    canvas[i][j] = '_';
                }
            }
            printf("\nCanvas Cleared\n");
        }
        else if (choice == 5) {
            printf("\nExiting \n");
        }
        else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}