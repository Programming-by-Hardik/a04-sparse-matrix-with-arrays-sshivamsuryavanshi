#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to create a sparse matrix from a given 2D array (dense matrix)
void createSparseMatrix(int denseMatrix[4][5], int rows, int cols, struct SparseMatrix sparse[], int *size) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (denseMatrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = denseMatrix[i][j];
                k++;
            }
        }
    }
    *size = k;
}

// Function to print the sparse matrix in triplet form
void printSparseMatrix(struct SparseMatrix sparse[], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

// Function to add two sparse matrices
void addSparseMatrices(struct SparseMatrix sparse1[], int size1, struct SparseMatrix sparse2[], int size2, struct SparseMatrix result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (sparse1[i].row < sparse2[j].row || (sparse1[i].row == sparse2[j].row && sparse1[i].col < sparse2[j].col)) {
            result[k++] = sparse1[i++];
        } else if (sparse2[j].row < sparse1[i].row || (sparse2[j].row == sparse1[i].row && sparse2[j].col < sparse1[i].col)) {
            result[k++] = sparse2[j++];
        } else {
            result[k].row = sparse1[i].row;
            result[k].col = sparse1[i].col;
            result[k].value = sparse1[i].value + sparse2[j].value;
            k++;
            i++;
            j++;
        }
    }

    // Add remaining elements
    while (i < size1) {
        result[k++] = sparse1[i++];
    }
    while (j < size2) {
        result[k++] = sparse2[j++];
    }

    *resultSize = k;
}

int main() {
    // Example dense matrices
    int denseMatrix1[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int denseMatrix2[4][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 4, 5}
    };

    struct SparseMatrix sparse1[20], sparse2[20], result[40];
    int size1, size2, resultSize;

    // Convert dense matrices to sparse form
    createSparseMatrix(denseMatrix1, 4, 5, sparse1, &size1);
    createSparseMatrix(denseMatrix2, 4, 5, sparse2, &size2);

    // Print the sparse matrices
    printf("Sparse Matrix 1:\n");
    printSparseMatrix(sparse1, size1);

    printf("\nSparse Matrix 2:\n");
    printSparseMatrix(sparse2, size2);

    // Add the two sparse matrices
    addSparseMatrices(sparse1, size1, sparse2, size2, result, &resultSize);

    // Print the result of addition
    printf("\nResultant Sparse Matrix after addition:\n");
    printSparseMatrix(result, resultSize);

    return 0;
}

    




