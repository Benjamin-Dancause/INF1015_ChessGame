#ifndef LOGICALBOARD_H
#define LOGICALBOARD_H
#include <vector>

enum LogicalPiece {WHITE_KING, WHITE_QUEEN, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK, WHITE_PAWN,
                   BLACK_KING, BLACK_QUEEN, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK, BLACK_PAWN, NOTHING};

class LogicalBoard
{
public:
    static LogicalBoard& getBoard();
    void setPiece(int x, int y, LogicalPiece piece);
    LogicalPiece getPiece(int x, int y);

private:
    LogicalBoard();
    static LogicalBoard board;
    std::vector<LogicalPiece> position;
};

bool isWhite(LogicalPiece piece);

#endif // LOGICALBOARD_H
