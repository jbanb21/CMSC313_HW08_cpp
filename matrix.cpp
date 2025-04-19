/*
File: matrix.cpp
Date: 4/19/2025
Desc: Driver file for matrix class
*/
#include "matrix.h"

Matrix::Matrix(int rows, int cols, int** matrix) {
    m_rows = rows;
    m_cols = cols; // Set columns to the passed value

    // Allocate memory for the matrix
    m_matrix = new int* [m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_matrix[i] = new int[m_cols];  // Create each row with variable columns
        for (int j = 0; j < m_cols; ++j) {
            m_matrix[i][j] = matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    removeMatrix();
}

void Matrix::removeMatrix() {
    //Clean up dynamically allocated memory for the 2D array
    for (int i = 0; i < m_rows; ++i) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;

}
void Matrix::print() const {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cout << m_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


void Matrix::transPoseMatrix() {
    // Create a temporary matrix to hold the transposed values
    int** tempMatrix = new int* [m_cols];
    for (int i = 0; i < m_cols; ++i) {
        tempMatrix[i] = new int[m_rows];
    }

    // Populate the temp matrix with transposed values
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            tempMatrix[j][i] = m_matrix[i][j];
        }
    }
    removeMatrix();
    m_matrix = tempMatrix;

    int x = m_rows;
    m_rows = m_cols;
    m_cols = x;
}


void Matrix::matrixAddition(Matrix &m) {
    
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] += m.m_matrix[i][j];
        }
    }


}


void Matrix::matrixMultiplication(Matrix& m) {
    if (m_cols != m.m_rows) {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication.");
    }

    int** tempMatrix = new int* [m_rows];
    for (int i = 0; i < m_rows; ++i) {
        tempMatrix[i] = new int[m.m_cols];
    }

    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m.m_cols; ++j) {
            tempMatrix[i][j] = 0;
            for (int k = 0; k < m_cols; ++k) {
                tempMatrix[i][j] += m_matrix[i][k] * m.m_matrix[k][j];
            }
        }
    }

    removeMatrix();  //deletes old m_matrix

    m_matrix = tempMatrix;
    m_cols = m.m_cols;  //update new column size
}

void Matrix::matrixMultiNum(int num) {

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] *= num;
        }
    }


}

