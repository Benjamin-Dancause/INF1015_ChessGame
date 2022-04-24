#include "Piece.h"
#include <iostream>

Piece::Piece()
{
    setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

Piece::Piece(int x, int y, Color color)
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

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;
    QMessageBox msg;
    msg.setText("Illegal move");
    std::cout << "x: " << x/75 << " y: " << y/75 << std::endl; //Debug tool, to be removed
    msg.exec();
    setPos(x + 7,y + 7);

    QGraphicsItem::mouseReleaseEvent((e));
}
