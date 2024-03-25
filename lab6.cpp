#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 1. Read data from input file and create NxN matrices.
void readMatrices(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2, const std::string& filePath) {
    std::ifstream file(filePath);
    int N;
    file >> N; // Read the size of the matrices
    matrix1.assign(N, std::vector<int>(N, 0));
    matrix2.assign(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix1[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix2[i][j];
        }
    }
}

// 2. Print the matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

// 3. Add both matrices together
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int N = matrix1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// 4. Subtract both matrices
std::vector<std::vector<int>> subtractMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int N = matrix1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// 5. Multiply matrices
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int N = matrix1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// 6. Update element in matrix
void updateMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col, int newValue) {
    if(row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {
        matrix[row][col] = newValue;
    }
}

// 7. Find the max value within the matrix
int getMaxValue(const std::vector<std::vector<int>>& matrix) {
    int maxVal = matrix[0][0];
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }
    return maxVal;
}

// 8. Transpose the matrix.
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int N = matrix.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
    std::string filePath = "matrix_input.txt"; // Adjust this to the location of your input file
    std::vector<std::vector<int>> matrix1, matrix2;

    // 1. Read the two matrices from the file
    readMatrices(matrix1, matrix2, filePath);

    // 2. Print the matrices
    std::cout << "Matrix 1:\n";
    printMatrix(matrix1);

    std::cout << "\nMatrix 2:\n";
    printMatrix(matrix2);

    // 3. Add the two matrices and print the result
    auto addedMatrix = addMatrices(matrix1, matrix2);
    std::cout << "\nAdded Matrix:\n";
    printMatrix(addedMatrix);

    // 4. Subtract the second matrix from first matrix and print the result
    auto subtractedMatrix = subtractMatrices(matrix1, matrix2);
    std::cout << "\nSubtracted Matrix (Matrix 1 - Matrix 2):\n";
    printMatrix(subtractedMatrix);

    // 5. Multiply the two matrices and print the result
    auto multipliedMatrix = multiplyMatrices(matrix1, matrix2);
    std::cout << "\nMultiplied Matrix (Matrix 1 * Matrix 2):\n";
    printMatrix(multipliedMatrix);

    // 6. Update an element in matrix1 for demonstration
    updateMatrixElement(matrix1, 0, 0, 100);
    std::cout << "\nUpdated Matrix 1 (after setting element [0][0] to 100):\n";
    printMatrix(matrix1);

    // 7. Find and print the max value of elements within the first matrix
    int maxValue = getMaxValue(matrix1);
    std::cout << "\nMaximum Value in Matrix 1: " << maxValue << "\n";

    // 8. Transpose the first matrix and print the result
    auto transposedMatrix = transposeMatrix(matrix1);
    std::cout << "\nTransposed Matrix 1:\n";
    printMatrix(transposedMatrix);
    return 0;
}
