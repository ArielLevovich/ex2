#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX
#include "my_mat.h"

// #define SIZE 10 // Define the size of the matrix

//question 2

/*

void findSumsRecursive(int arr[], int n, int target, int start, int currentSum, bool *found, int currentElements[], int currentCount) {
    // If the current sum is equal to target, display the elements
    if (currentSum == target) {
        printf("Sum found with elements: ");
        for (int i = 0; i < currentCount; i++) {
            printf("%d ", currentElements[i]);
        }
        printf("\n");
        *found = true;
        return;
    }

    // If we reached the end of the array, return
    if (start == n) {
        return;
    }

    // Include the current element
    currentElements[currentCount] = arr[start];
    findSumsRecursive(arr, n, target, start + 1, currentSum + arr[start], found, currentElements, currentCount + 1);

    // Exclude the current element
    findSumsRecursive(arr, n, target, start + 1, currentSum, found, currentElements, currentCount);
}



void selectItems(float weights[], float values[], char *strings[], int numStrings)
{
    int c = 20;
    *strings = NULL;
    if (numStrings != 5) {
        printf("The number of items must be 5\n");
        return;
    }
    if(sizeof(weights)/sizeof(weights[0]) != 5 || sizeof(values)/sizeof(values[0]) != 5){
        printf("your array is not 5*5\n");
        return;
    }

    int rows = numStrings + 1;
    int table[rows][c + 1];
    int keep[rows][c + 1];
    int table[rows][c + 1];

    for(int i=0;i<rows;i++){
        for(int j=0;j<c+1;j++){
            table[i][j] = 0;
            keep[i][j] = 0;
        }
    }

    for(int row=1;row++;row<rows){
        for(int col=1;col++;col<c+1){
            if (col >= weights[row]) {
                int diff = col-weights[row];
                table[row][col] = max(table[row-1][col], table[row-1][diff]);
            }
            else{
                table[row][col] = max(table[row-1][col], 0);
            }
        }
    }

    
}
*/

// inputs a matrix from the stdin.
// the allocated matrix with size n*n is returned by reference
void inputMatrix(int ***matrix, int size) {        
    if (size > 0) {
        // Allocate memory for the output matrix
        *matrix = (int **)malloc(size * sizeof(int *)); // second *
        int **mtrx = *matrix;

        for (int i = 0; i < size; i++) {
            mtrx[i] = (int *)malloc(size * sizeof(int)); // third *
        }       

        // Read matrix values from stdin
        // printf("Enter the matrix values (%d x %d):\n", size, size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                scanf("%d", &mtrx[i][j]);
            }
        }

        // *mtrx[8] = 99; // mtrx[0][8]
        // (*mtrx +4)[8] = 13; // mtrx[4][8]
    }    
}

// gets input: i and j from the stdin.
// prints to the stdout "True" if the path (i->j) exists, and "False" otherwise.
void displayIfPathExists(int **matrix, int n) {
    int i, j;
    // printf("Enter i and j separated by whitespace: ");
    scanf("%d %d", &i, &j);

    displayIfPathExistsInternal(matrix, n, i, j);
}

// gets input: i and j from the stdin.
// prints to the stdout the shortest path (i->j) if exists, and -1 otherwise.
void displayTheShortestPath(int **matrix, int n) {
    int i, j;
    // printf("Enter i and j separated by whitespace: ");
    scanf("%d %d", &i, &j);

    displayTheShortestPathInternal(matrix, n, i, j);
}

// prints to the stdout "True" if the path exists, and "False" otherwise.
void displayIfPathExistsInternal(int **matrix, int n, int i, int j) {
    int **clone = floydWarshall(matrix, n);
    if (clone[i][j] != INT_MAX && i != j) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }

    // Free the allocated matrix.
    freeMatrixMemory(&clone, n);
}

// prints to the stdout the shortest path if exists, and -1 otherwise.
void displayTheShortestPathInternal(int **matrix, int n, int i, int j) {
    int **clone = floydWarshall(matrix, n);
    if (clone[i][j] != INT_MAX && i != j) {
        printf("%d\n", clone[i][j]);
    }
    else {
        printf("-1\n");
    }

    // Free the allocated matrix.
    freeMatrixMemory(&clone, n);
}

// Function to swap zeros with INT_MAX except where i == j
void replaceZerosWithIntMax(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0 && i != j) {
                matrix[i][j] = INT_MAX;
            }
        }
    }
}

// Function to implement Floyd-Warshall algorithm
int** floydWarshall(int **matrix, int n) {
    int **clone = cloneMatrix(matrix, n);
    
    replaceZerosWithIntMax(clone, n);

    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (clone[i][k] != INT_MAX && clone[k][j] != INT_MAX && 
                    clone[i][k] + clone[k][j] < clone[i][j])
                    clone[i][j] = clone[i][k] + clone[k][j];
            }
        }
    }
    return clone;
}

int** cloneMatrix(int **matrix, int n) {
    // Allocate memory for the output matrix
    int **clone = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        clone[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            clone[i][j] = matrix[i][j];
        }
    }
    return clone;
}

void freeMatrixMemory(int ***matrix, int n) {
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
    // mark parameters to contain initial values.
    *matrix = NULL;
}
