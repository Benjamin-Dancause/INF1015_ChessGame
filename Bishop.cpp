#include "Bishop.h"

Bishop::Bishop(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == WHITE)
    {
        pieceType_ = WHITE_BISHOP;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_blt60.png"));
    }
    else
    {
        pieceType_ = BLACK_BISHOP;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Bishop::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
