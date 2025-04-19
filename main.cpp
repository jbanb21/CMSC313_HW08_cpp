/*
File: main.cpp
Date: 4/19/2025
Desc: driver file for project
*/
#include "matrix.h"

int main() {
	//Variables
	string equName = "D";
	string equ = "A + (3*B) x C^T";
    //Print
    cout << equName << " = " << equ << endl;
    cout << "Calculating...\n";
    //Max rows and cols
    int rows = 2;
    int cols = 2;

    //Dynamically create a 2D array for matrix
    int** matA = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matA[i] = new int[cols];  
    }

    //Initialize matrix data
    matA[0][0] = 6; matA[0][1] = 4; 
    matA[1][0] = 8; matA[1][1] = 3;

    //Create the matrix object with the dynamic 2D array
    Matrix A(2, 2, matA);
    //A.print();

    //Max rows and cols
    rows = 2;
    cols = 3;
    //Dynamically create a 2D array for matrix
    int** matB = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matB[i] = new int[cols];
    }
    //Initialize matrix data
    matB[0][0] = 1; matB[0][1] = 2; matB[0][2] = 3;
    matB[1][0] = 4; matB[1][1] = 5; matB[1][2] = 6;

    //Create the matrix object with the dynamic 2D array
    Matrix B(2, 3, matB);
    //B.print();

    //Max rows and cols
    rows = 2;
    cols = 3;
    //Dynamically create a 2D array for matrix
    int** matC = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matC[i] = new int[cols];
    }
    //Initialize matrix data
    matC[0][0] = 2; matC[0][1] = 4; matC[0][2] = 6;
    matC[1][0] = 1; matC[1][1] = 3; matC[1][2] = 5;

    //Create the matrix object with the dynamic 2D array
    Matrix C(2, 3, matC);
    //C.print();
    //Computations
    //First Part of equation C^T
    C.transPoseMatrix();
    //C.print();
    //Second 3*B
    B.matrixMultiNum(3);
    //3rd B * C
    B.matrixMultiplication(C);
    //B.print();
    //Then finally adds A+B
    A.matrixAddition(B);
    A.print();

    //Delete temp memory
    for (int i = 0; i < rows; ++i) {
        delete[] matA[i];
    }
    delete[] matA;

    for (int i = 0; i < rows; ++i) {
        delete[] matB[i];
    }
    delete[] matB;

    for (int i = 0; i < rows; ++i) {
        delete[] matC[i];
    }
    delete[] matC;

	return 0;
}