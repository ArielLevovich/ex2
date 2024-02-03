#include <stdio.h>
#include "my_mat.h"

int main() {
    char command;
    int **matrix = NULL;
    int n = 0;

    while (1) {
        printf("Enter command (A, B, C, D): ");
        scanf(" %c", &command); // Note the space before %c to consume any newline characters left in the input buffer

        switch (command) {
            case 'A':
                if (matrix != NULL && n > 0) {
                    freeMatrixMemory(&matrix, &n);                    
                }
                inputMatrix(&matrix, &n);                
                break;
            case 'B':
                if (matrix != NULL && n > 0) {
                    displayIfPathExists(matrix, n);
                } else {
                    printf("Matrix not initialized.\n");
                }
                break;
            case 'C':
                if (matrix != NULL && n > 0) {
                    displayTheShortestPath(matrix, n);
                } else {
                    printf("Matrix not initialized.\n");
                }
                break;
            case 'D':
                printf("Exiting...\n");
                freeMatrixMemory(&matrix, &n);
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }
}
