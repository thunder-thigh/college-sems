#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices A and B of size n and store result in C
void add(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract matrix B from A and store result in C
void subtract(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to allocate memory for an n x n matrix
int** allocate_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
    return matrix;
}

// Function to free the allocated matrix memory
void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

// Strassen’s multiplication function
void strassen(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    // Allocate submatrices
    int **A11 = allocate_matrix(newSize);
    int **A12 = allocate_matrix(newSize);
    int **A21 = allocate_matrix(newSize);
    int **A22 = allocate_matrix(newSize);

    int **B11 = allocate_matrix(newSize);
    int **B12 = allocate_matrix(newSize);
    int **B21 = allocate_matrix(newSize);
    int **B22 = allocate_matrix(newSize);

    int **C11 = allocate_matrix(newSize);
    int **C12 = allocate_matrix(newSize);
    int **C21 = allocate_matrix(newSize);
    int **C22 = allocate_matrix(newSize);

    int **M1 = allocate_matrix(newSize);
    int **M2 = allocate_matrix(newSize);
    int **M3 = allocate_matrix(newSize);
    int **M4 = allocate_matrix(newSize);
    int **M5 = allocate_matrix(newSize);
    int **M6 = allocate_matrix(newSize);
    int **M7 = allocate_matrix(newSize);

    int **AResult = allocate_matrix(newSize);
    int **BResult = allocate_matrix(newSize);

    // Dividing matrices A and B into 4 submatrices each
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    add(newSize, A11, A22, AResult);
    add(newSize, B11, B22, BResult);
    strassen(newSize, AResult, BResult, M1);

    // M2 = (A21 + A22) * B11
    add(newSize, A21, A22, AResult);
    strassen(newSize, AResult, B11, M2);

    // M3 = A11 * (B12 - B22)
    subtract(newSize, B12, B22, BResult);
    strassen(newSize, A11, BResult, M3);

    // M4 = A22 * (B21 - B11)
    subtract(newSize, B21, B11, BResult);
    strassen(newSize, A22, BResult, M4);

    // M5 = (A11 + A12) * B22
    add(newSize, A11, A12, AResult);
    strassen(newSize, AResult, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(newSize, A21, A11, AResult);
    add(newSize, B11, B12, BResult);
    strassen(newSize, AResult, BResult, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(newSize, A12, A22, AResult);
    add(newSize, B21, B22, BResult);
    strassen(newSize, AResult, BResult, M7);

    // Calculating C11, C12, C21, C22
    // C11 = M1 + M4 - M5 + M7
    add(newSize, M1, M4, AResult);
    subtract(newSize, AResult, M5, BResult);
    add(newSize, BResult, M7, C11);

    // C12 = M3 + M5
    add(newSize, M3, M5, C12);

    // C21 = M2 + M4
    add(newSize, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    subtract(newSize, M1, M2, AResult);
    add(newSize, AResult, M3, BResult);
    add(newSize, BResult, M6, C22);

    // Grouping results into the final matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free all allocated memory
    free_matrix(A11, newSize); free_matrix(A12, newSize);
    free_matrix(A21, newSize); free_matrix(A22, newSize);
    free_matrix(B11, newSize); free_matrix(B12, newSize);
    free_matrix(B21, newSize); free_matrix(B22, newSize);
    free_matrix(C11, newSize); free_matrix(C12, newSize);
    free_matrix(C21, newSize); free_matrix(C22, newSize);
    free_matrix(M1, newSize); free_matrix(M2, newSize);
    free_matrix(M3, newSize); free_matrix(M4, newSize);
    free_matrix(M5, newSize); free_matrix(M6, newSize);
    free_matrix(M7, newSize); free_matrix(AResult, newSize);
    free_matrix(BResult, newSize);
}

// Helper function to print a matrix
void print_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;  // For simplicity, use n as a power of 2

    // Allocate matrices
    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    int **C = allocate_matrix(n);

    // Initialize matrices A and B with some values
    int counter = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = counter++;

    counter = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = counter++;

    printf("Matrix A:\n");
    print_matrix(n, A);

    printf("\nMatrix B:\n");
    print_matrix(n, B);

    // Multiply A and B using Strassen
    strassen(n, A, B, C);

    printf("\nResult Matrix C (A x B):\n");
    print_matrix(n, C);

    // Free allocated memory
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}

