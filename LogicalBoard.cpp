#include "LogicalBoard.h"

LogicalBoard LogicalBoard::board;

LogicalBoard LogicalBoard::getBoard()
{
    return board;
}

void LogicalBoard::setPiece(int x, int y, LogicalPiece piece)
{
    position[x][y] = piece;
}

LogicalPiece LogicalBoard::getPiece(int x, int y)
{
    return position[x][y];
}



LogicalBoard::LogicalBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            position[i][j] = NOTHING;
        }
    }
}

