#include "FasterEightQueens.h"
#include <iostream>
#include <stdexcept>
#include <cmath> //std::abs
//Initialize the board
FasterEightQueens::FasterEightQueens() : sideSize (8){
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
FasterEightQueens::~FasterEightQueens()
{
    for (int i = 0; i < sideSize; ++i) {
        for (int j = 0; j < sideSize; ++j) {
            delete [] chessBoard[i];
        }
    }
    delete [] chessBoard;
}
//Construct the board through the initial calling
void FasterEightQueens::ConstructBoard () {
   // if (!PlaceQueens(0))
      //  throw std::runtime_error ("Board does not exist. ");
      PlaceQueens(0);
}
//Use backtracking when placing queens per column
bool FasterEightQueens::PlaceQueens (int column) {
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
bool FasterEightQueens::CheckOverlap (int x, int y) {
    //Check if a queen intercepts the newly inputted queen
    //Check the rows, going backwards from the current column
    for (int i = y; i >= 0; --i) {
        ++checkOverlapComparisons;
        if (chessBoard[x][i]) return true;
    }
    //Check the upper right diagonals
    for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
        ++checkOverlapComparisons;
        if (chessBoard[i][j]) return true;
    }
    //Check the lower right diagonals
    for (int i = x, j = y; i < sideSize && j >= 0; ++i,  --j) {
        ++checkOverlapComparisons;
        if (chessBoard[i][j]) return true;
    }
    return false;
}
//Print the chess board
void FasterEightQueens::PrintBoard () {
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
    std::cout << "Number of Compares: " << checkOverlapComparisons << std::endl;

}
