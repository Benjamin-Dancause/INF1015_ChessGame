#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>

#include "Piece.h"
#include "Tile.h"


class Board : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);
    ~Board();
    QList<Piece*> pieces;
    QList<Tile*> tiles;
private:
    int logicalBoard[8][8]; // this might be useless

signals:

};

#endif // BOARD_H
