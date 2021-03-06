#ifndef EIGHTQUEENS_H
#define EIGHTQUEENS_H

//Implementation of the Eight Queens Problem
class EightQueens
{
    public:
        EightQueens ();
        virtual ~EightQueens ();
        void ConstructBoard ();
        bool PlaceQueens (int column);
        bool CheckOverlap(int x, int y);
        void PrintBoard();

    private:
        int ** chessBoard;
        const int sideSize;
        int checkOverlapComparisons = 0;
        int numberOfLoops = 0;
};

#endif // EIGHTQUEENS_H
