#include "Queen.h"

Queen::Queen(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType = BLACK_QUEEN;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_qdt60.png"));
    }
    else
    {
        pieceType = WHITE_QUEEN;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_qlt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Queen::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
