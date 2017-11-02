#include <iostream>
#include "EightQueens.h"
#include "FasterEightQueens.h"

int main()
{
    //Slower 8 Queens Algorithm
    std::cout << "\t-----Slower 8 Queens Algorithm-----\n";
    EightQueens * checkmate = new EightQueens ();
    checkmate->ConstructBoard();
    checkmate->PrintBoard();
    //Faster 8 Queens Algorithm
    std::cout << "\t-----Faster 8 Queens Algorithm-----\n";
    FasterEightQueens * fastCheckmate = new FasterEightQueens ();
    fastCheckmate->ConstructBoard();
    fastCheckmate->PrintBoard();
    return 0;
}

