#include "Piece.h"

Piece::Piece()
{
    setRect(0, 0, tile_size, tile_size);
    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::blue));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

Piece::Piece(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    setRect(x*tile_size, y*tile_size, tile_size, tile_size);
    setPen(QPen(Qt::black));
    if (color == BLACK)
    {
        setBrush(QBrush(Qt::blue));
    }
    else
    {
        setBrush(QBrush(Qt::red));
    }
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) // Doesn't always work, but it will do for now
{
    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;
    setPos(x,y);
    QGraphicsRectItem::mouseReleaseEvent((e));
}
