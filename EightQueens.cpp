#include "EightQueens.h"
#include <iostream>
#include <stdexcept>
#include <cmath> //std::abs
//Initialize the board
EightQueens::EightQueens() : sideSize (8){
    chessBoard = new int * [sideSize];
    for (int i = 0; i < sideSize; ++i) {
        chessBoard[i] = new int [sideSize];
    }
    //Initialize values to 0
    for (int i = 0; i < sideSize; ++i) {
        for (int j = 0; j < sideSize; ++j) {
            chessBoard[i][j] = 0;
        }
    }
}
//Deallocate the memory in the destructor
EightQueens::~EightQueens()
{
    for (int i = 0; i < sideSize; ++i) {
        for (int j = 0; j < sideSize; ++j) {
            delete [] chessBoard[i];
        }
    }
    delete [] chessBoard;
}
//Construct the board through the initial calling
void EightQueens::ConstructBoard () {
    if (!PlaceQueens(0))
        throw std::runtime_error ("Board does not exist. ");
}
//Use backtracking when placing queens per column
bool EightQueens::PlaceQueens (int column) {
    //If all the queens have been placed
    if (column >= sideSize)
        return true;
    //Place the queens if they do not intersect one another
    for (int row = 0; row < sideSize; ++row) {
        if (!CheckOverlap(row, column)) {
            //Put a one to signify that it is true that there is a queen there
            chessBoard[row][column] = 1;
            //If the next queen can be placed, do not backtrack
            if (PlaceQueens(column + 1)) return true;
            //If the next column does not satisfy the requirement we backtrack
            chessBoard[row][column] = 0;
        }
    }
    return false;
}
//Check if there is a checkmate between the queens
bool EightQueens::CheckOverlap (int x, int y) {
    //Check rows and columns
    for (int i = 0; i < sideSize; ++i) {
        for (int j = 0; j < sideSize; ++j) {
            //Check if overlapping another queen horizontally
            if (i == x && chessBoard[i][j]) return true;
            //Check if overlapping another queen vertically
            if (j == y && chessBoard[i][j]) return true;
            //Check diagonals, there is a correlation between the row and columns abs values
            if (abs(x - i) == abs(j - y) && chessBoard[i][j]) return true;
        }
    }
    return false;
}
//Print the chess board
void EightQueens::PrintBoard () {
    int counter = 0;
    for (int i = 0; i < sideSize; ++i) {
        for (int j = 0; j < sideSize; ++j) {
            //If we have reached the end of the row
            if (counter % 8 == 0)
                std::cout << std::endl;
            std::cout << chessBoard[i][j] << "\t";
            ++counter;
        }
    }
}
