#include "Bishop.h"

Bishop::Bishop(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_blt60.png"));
    }

    setPos(x, y);
}

void Bishop::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
