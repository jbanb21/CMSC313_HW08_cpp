/*
File: matrix.h
Date: 4/19/2025
Desc: header file for matrix class
*/
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
private:
    int m_rows;
    int m_cols;
    int** m_matrix;

public:
    Matrix(int rows, int cols, int** matrix); // constructor updated to use variable cols
    ~Matrix();
    void transPoseMatrix();
    void removeMatrix();
    void print() const;
    void matrixAddition(Matrix &m);
    void matrixMultiplication(Matrix& m);
    void matrixMultiNum(int num);
};

#endif

