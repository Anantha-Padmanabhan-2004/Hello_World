#include <iostream>

class Matrix {
private:
    int* data;
    int size;

public:
    Matrix(int n) {
        size = n;
        data = new int[size * size];
    }

    ~Matrix() {
        delete[] data;
    }

    void fill() {
        std::cout << "Enter matrix elements row by row:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cin >> data[i * size + j];
            }
        }
    }

    friend Matrix multiply(const Matrix& mat1, const Matrix& mat2);
};

// Friend function for matrix multiplication
Matrix multiply(const Matrix& mat1, const Matrix& mat2) {
    int size = mat1.size;
    Matrix result(size);

    // Perform matrix multiplication
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i * size + j] = 0;
            for (int k = 0; k < size; k++) {
                result.data[i * size + j] += mat1.data[i * size + k] * mat2.data[k * size + j];
            }
        }
    }

    return result;
}

int main() {
    int size;
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> size;

    // Create the first matrix
    Matrix matrix1(size);
    std::cout << "Enter values for the first matrix:\n";
    matrix1.fill();

    // Create the second matrix
    Matrix matrix2(size);
    std::cout << "Enter values for the second matrix:\n";
    matrix2.fill();

    // Perform matrix multiplication and get the result
    Matrix result = multiply(matrix1, matrix2);

    std::cout << "Resultant matrix after multiplication:\n";
    // Display the resultant matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << result.data[i * size + j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
