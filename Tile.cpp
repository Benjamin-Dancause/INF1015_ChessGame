#include "Tile.h"

Tile::Tile()
{
    setRect(0, 0, tile_size, tile_size);
    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::black));
}

void Tile::setWhite()
{
    setBrush(QBrush(Qt::white));
}
