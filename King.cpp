#include "King.h"

King::King(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType_ = BLACK_KING;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_kdt60.png"));
    }
    else
    {
        pieceType_ = WHITE_KING;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_klt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void King::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;
    if (x_ == x && y_ == y)
    {
        updateBoard(x,y);
    }
    if (color_ == WHITE)
    {
        if (!(std::abs(x_-x) <= 1 && std::abs(y_-y) <= 1))
        {
            invalideMove();
        }
        else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
        {
            invalideMove();
        }
        else if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
        {
            updateBoard(x,y);
        }
        else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
        {
            capture.hasCaptured(x,y);
            updateBoard(x,y);
        }
    }
    else
    {
        if (!(std::abs(x_-x) <= 1 && std::abs(y_-y) <= 1))
        {
            invalideMove();
        }
        else if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
        {
            updateBoard(x,y);
        }
        else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
        {
            capture.hasCaptured(x,y);
            updateBoard(x,y);
        }
        else
        {
            invalideMove();
        }
    }
    QGraphicsItem::mouseReleaseEvent((e));
}
