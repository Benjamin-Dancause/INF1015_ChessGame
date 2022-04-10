#ifndef PIECE_H
#define PIECE_H

#ifndef tile_size
#define tile_size 75
#endif

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>

class Piece : public QGraphicsRectItem //possible memory leak
{
public:
    Piece();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // PIECE_H
