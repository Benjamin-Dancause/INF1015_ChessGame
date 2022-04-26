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

}
