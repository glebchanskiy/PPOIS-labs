//
// Created by Глеб on 2.09.22.
//

#include "gtest/gtest.h"
#include "Matrix.h"

#define RESOURCES_PATH "/Users/glebchanskiy/Workspace/subjects/pivo/sem3/PPOIS-labs/lab1/resources/"

TEST(matrixTypeCheck, diagonalMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile( RESOURCES_PATH "diagonal_matrix.txt");
    EXPECT_EQ(m.isDiagonalMatrix(), true);
}

TEST(matrixTypeCheck, SquareMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "square_matrix.txt");
    EXPECT_EQ(m.isSquareMatrix(), true);
}

TEST(matrixTypeCheck, ZeroMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "zero_matrix.txt");
    EXPECT_EQ(m.isZeroMatrix(), true);
}

TEST(matrixTypeCheck, UnitMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "unit_matrix.txt");
    EXPECT_EQ(m.isUnitMatrix(), true);
}

TEST(matrixTypeCheck, SymmetricalMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "sym_matrix.txt");
    EXPECT_EQ(m.isSymmetricalMatrix(), true);
}

TEST(matrixTypeCheck, LowerTriangularMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "upper_matrix.txt");
    EXPECT_EQ(m.isLowerTriangularMatrix(), true);
}

TEST(matrixTypeCheck, UpperTriangularMatrix) {
    Matrix<int> m = Matrix<int>();

    m.loadFromFile(RESOURCES_PATH "lower_matrix.txt");
    EXPECT_EQ(m.isUpperTriangularMatrix(), true);
}

TEST(matrixGetTransponentMatrixCheck, x3matrix) {
    Matrix<int> m = Matrix<int>();
    m.loadFromFile(RESOURCES_PATH "matrixToBeTransp.txt");

    Matrix<int> T = m.getTransMatrix();

    for (int i=0; i<T.getRows(); i++)
        for (int j=0; j<T.getColumns(); j++)
            EXPECT_EQ(T.getValue(i,j), m.getValue(j,i));
}

TEST(matrixGetSubMatrixCheck, x5matrix) {
    Matrix<int> m = Matrix<int>();
    m.loadFromFile(RESOURCES_PATH "big_matrix.txt");

    Matrix<int> correct_sub = Matrix<int>();
    correct_sub.loadFromFile(RESOURCES_PATH "sub_matrix_of_big_matrix.txt");

    Matrix<int> sub_m = m.getSubMatrix(1,1,3,3);

    for (int i=0; i<correct_sub.getRows(); i++)
        for (int j=0; j<correct_sub.getColumns(); j++)
            EXPECT_EQ(sub_m.getValue(i,j), correct_sub.getValue(i,j));
}

TEST(matrixGetSubMatrixCheck, x3matrix) {
    Matrix<int> m = Matrix<int>();
    m.loadFromFile(RESOURCES_PATH "midle_matrix.txt");

    Matrix<int> correct_sub = Matrix<int>();
    correct_sub.loadFromFile(RESOURCES_PATH "sub_matrix_of_big_matrix.txt");

    Matrix<int> sub_m = m.getSubMatrix(0,0,3,3);

    for (int i=0; i<correct_sub.getRows(); i++)
        for (int j=0; j<correct_sub.getColumns(); j++)
            EXPECT_EQ(sub_m.getValue(i,j), correct_sub.getValue(i,j));
}

TEST(matrixConstructorCheck, withoutArgumens) {
    Matrix<int> m = Matrix<int>();
    EXPECT_EQ(m.getRows(), 0);
    EXPECT_EQ(m.getColumns(), 0);
}

TEST(matrixConstructorCheck, with2Argumens) {
    Matrix<int> m = Matrix<int>(3,4);
    EXPECT_EQ(m.getRows(), 3);
    EXPECT_EQ(m.getColumns(), 4);
}