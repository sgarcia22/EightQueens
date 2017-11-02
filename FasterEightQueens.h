#ifndef FASTEREIGHTQUEENS_H
#define FASTEREIGHTQUEENS_H

//Implementation of the Eight Queens Problem
class FasterEightQueens
{
    public:
        FasterEightQueens ();
        virtual ~FasterEightQueens ();
        void ConstructBoard ();
        bool PlaceQueens (int column);
        bool CheckOverlap(int x, int y);
        void PrintBoard();

    private:
        int ** chessBoard;
        const int sideSize;
        int checkOverlapComparisons = 0;
};

#endif // FASTEREIGHTQUEENS_H
