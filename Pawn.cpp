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

    setPos(x, y);
}

void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;

    QMessageBox msg;
    msg.setText("Illegal move");
    //std::cout << "x: " << x/75 << " y: " << y/75 << std::endl; //Debug tool, to be removed
    msg.exec();
    setPos(x + 7, y + 7);
    if (isFirstMove) {isFirstMove = false;}
    QGraphicsItem::mouseReleaseEvent((e));
}
