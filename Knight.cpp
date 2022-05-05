#include "Knight.h"
#include <iostream>

Knight::Knight(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType_ = BLACK_KNIGHT;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_ndt60.png"));
    }
    else
    {
        pieceType_ = WHITE_KNIGHT;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_nlt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Knight::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;
    if (color_ == WHITE)
    {
        if (LogicalBoard::getBoard().isWhiteTurn())
        {
            if        ((x_ + 2 == x && (y_ + 1 == y || y_ - 1 == y))
                    || (x_ - 2 == x && (y_ + 1 == y || y_ - 1 == y))
                    || (y_ + 2 == y && (x_ + 1 == x || x_ - 1 == x))
                    || (y_ - 2 == y && (x_ + 1 == x || x_ - 1 == x)))
            {
                std::cout << "knit moves h" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                {
                    invalideMove();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    messenger.hasCaptured(x,y);
                    updateBoard(x,y);
                }
            }
            else if (x_ == x && y_ == y)
            {
                updateBoard(x,y);
            }
            else
            {
                invalideMove();
            }
        }
        else
        {
            wrongSide();
        }
    }
    else
    {
        if (!LogicalBoard::getBoard().isWhiteTurn())
        {
            if        ((x_ + 2 == x && (y_ + 1 == y || y_ - 1 == y))
                    || (x_ - 2 == x && (y_ + 1 == y || y_ - 1 == y))
                    || (y_ + 2 == y && (x_ + 1 == x || x_ - 1 == x))
                    || (y_ - 2 == y && (x_ + 1 == x || x_ - 1 == x)))
            {
                std::cout << "knit moves h" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                {
                    invalideMove();
                }
                else
                {
                    messenger.hasCaptured(x,y);
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
            }
            else if (x_ == x && y_ == y)
            {
                updateBoard(x,y);
            }
            else
            {
                invalideMove();
            }
        }
        else
        {
            wrongSide();
        }
    }
    QGraphicsItem::mouseReleaseEvent((e));
}
