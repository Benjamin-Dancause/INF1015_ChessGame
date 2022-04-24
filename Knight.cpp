#include "Knight.h"

Knight::Knight(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_ndt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_nlt60.png"));
    }
}

void Knight::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
