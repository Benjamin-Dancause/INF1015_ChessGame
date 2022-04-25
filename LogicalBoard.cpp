#include "LogicalBoard.h"

LogicalBoard LogicalBoard::board;

LogicalBoard& LogicalBoard::getBoard()
{
    return board;
}

void LogicalBoard::setPiece(int x, int y, LogicalPiece piece)
{
    position[8*y + x] = piece;
}

LogicalPiece LogicalBoard::getPiece(int x, int y)
{
    return position[8*y + x];
}



LogicalBoard::LogicalBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            position.push_back(NOTHING);
        }
    }
}




bool isWhite(LogicalPiece piece)
{
    return (piece < BLACK_KING);
}
