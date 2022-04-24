#ifndef LOGICALBOARD_H
#define LOGICALBOARD_H


enum LogicalPiece {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};

class LogicalBoard
{
public:
    static LogicalBoard getBoard();
    LogicalPiece position[8][8];

private:
    LogicalBoard();
    static LogicalBoard board;
};

#endif // LOGICALBOARD_H
