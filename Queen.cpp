#include "Queen.h"

Queen::Queen(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_qdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_qlt60.png"));
    }
}

void Queen::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
