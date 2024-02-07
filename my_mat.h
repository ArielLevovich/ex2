#ifndef MY_MAT
#define MY_MAT

#define SIZE_ITEMS 5 
#define TOTAL_WEIGHT 20

int selectItems(int weights[], int values[] , int selected_bool[]);
// gets a matrix input from the stdin.
// the allocated matrix with size n*n is returned by reference
void inputMatrix(int ***matrix, int n); 

// gets input: i and j from the stdin.
// prints to the stdout "True" if the path (i->j) exists, and "False" otherwise.
void displayIfPathExists(int **matrix, int n);

// gets input: i and j from the stdin.
// prints to the stdout the shortest path (i->j) if exists, and -1 otherwise.
void displayTheShortestPath(int **matrix, int n);

// free the allocated matrix memory
void freeMatrixMemory(int ***matrix, int n);

// helper functions - should not be called outside "my_mat.c"
void displayIfPathExistsInternal(int **matrix, int n, int i, int j);
void displayTheShortestPathInternal(int **matrix, int n, int i, int j);
void replaceZerosWithIntMax(int **matrix, int n);
int** floydWarshall(int **matrix, int n);
int** cloneMatrix(int **matrix, int n);
#endif