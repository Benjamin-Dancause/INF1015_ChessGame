#include "Piece.h"

Piece::Piece()
{
    setRect(0, 0, tile_size, tile_size);
    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::blue));
    setFlag(QGraphicsItem::ItemIsMovable);
    //setFlag(QGraphicsItem::ItemIsSelectable);
}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = pos().x() - (int) pos().x() % tile_size;
    int y = pos().y() - (int) pos().y() % tile_size;
    setPos(x,y);

}
