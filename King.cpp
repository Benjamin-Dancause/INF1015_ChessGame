#include "King.h"

King::King(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_kdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_klt60.png"));
    }

    setPos(x, y);
}

void King::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
