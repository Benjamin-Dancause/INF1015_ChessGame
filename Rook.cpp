#include "Rook.h"

Rook::Rook(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType_ = BLACK_ROOK;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_rdt60.png"));
    }
    else
    {
        pieceType_ = WHITE_ROOK;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_rlt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Rook::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
