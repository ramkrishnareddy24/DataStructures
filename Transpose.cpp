#include <bits/stdc++.h>
using namespace std;

// Function to fill a matrix with increasing values
void fillMatrix(int matrix[][3], int rows, int cols) {
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void transpose(int matrix[][3],int rows,int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main() {
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols];
    
    // Fill the matrix with increasing values
    fillMatrix(matrix, rows, cols);
    
    // Display the matrix
    transpose(matrix,rows,cols);
    displayMatrix(matrix, rows, cols);
    
    return 0;
}
