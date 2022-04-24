#ifndef LOGICALBOARD_H
#define LOGICALBOARD_H


enum LogicalPiece {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, NOTHING};

class LogicalBoard
{
public:
    static LogicalBoard getBoard();
    void setPiece(int x, int y, LogicalPiece piece);
    LogicalPiece getPiece(int x, int y);

private:
    LogicalBoard();
    static LogicalBoard board;
    LogicalPiece position[8][8];
};

#endif // LOGICALBOARD_H
