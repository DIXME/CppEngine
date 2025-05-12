#ifndef __MATRIX__
#define __MATRIX__

#include <vector>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data; // 2D container for matrix elements
    size_t rows, cols;                // Dimensions of the matrix

public:
    // Constructor: Initialize matrix with given dimensions and default value
    Matrix(size_t rows, size_t cols, T defaultValue = T())
        : rows(rows), cols(cols), data(rows, std::vector<T>(cols, defaultValue)) {}

    // Constructor: Initialize matrix from a 2D array
    Matrix(const std::vector<std::vector<T>>& inputData)
        : data(inputData), rows(inputData.size()), cols(inputData.empty() ? 0 : inputData[0].size()) {
        // Ensure all rows have the same number of columns
        for (const auto& row : inputData) {
            if (row.size() != cols) {
                throw std::invalid_argument("All rows in the 2D array must have the same number of columns");
            }
        }
    }

    // Accessors for dimensions
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Access element (read/write)
    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[row][col];
    }

    // Print the matrix
    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    // Matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.at(i, j) = this->at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }

        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }

    // Get the type of the matrix (e.g., mat4x4, mat3x3)
    std::string getType() const {
        return "Matrix<" + std::string(typeid(T).name()) + ">[" + std::to_string(rows) + "x" + std::to_string(cols) + "]";
    }
};

#endif // __MATRIX__