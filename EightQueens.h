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
};

#endif // EIGHTQUEENS_H
