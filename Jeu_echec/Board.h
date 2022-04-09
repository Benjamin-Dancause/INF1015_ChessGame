#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>

#include "Piece.h"
#include "Tile.h"
#define tile_size 75
class Board : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);
    ~Board();
    QList<Piece*> pieces;
    QList<Tile*> tiles;

signals:

};

#endif // BOARD_H
