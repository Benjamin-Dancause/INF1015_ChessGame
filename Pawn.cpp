#include "Pawn.h"

Pawn::Pawn(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_pdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_plt60.png"));
    }
}

void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
