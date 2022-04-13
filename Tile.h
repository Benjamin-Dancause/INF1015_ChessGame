#ifndef TILE_H
#define TILE_H

#ifndef tile_size
#define tile_size 75
#endif

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>

class Tile : public QGraphicsRectItem // possible memory leak
{
public:
    Tile();
    void setWhite();
private:
};

#endif // TILE_H
