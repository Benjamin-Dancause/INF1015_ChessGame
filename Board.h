#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Tile.h"
#include "LogicalBoard.h"


class Board : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);
    ~Board();
private:
    QGraphicsView* view_;
    QList<Piece*> pieces_;
    QList<Tile*> tiles_;
public slots:
void hidePiece(int x, int y);
};

#endif // BOARD_H
