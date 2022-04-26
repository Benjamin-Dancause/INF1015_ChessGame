#ifndef PIECE_H
#define PIECE_H

#ifndef tile_size
#define tile_size 75
#endif

#ifndef piece_adjust
#define piece_adjust 7
#endif

#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <cstdlib>
#include "LogicalBoard.h"

enum Color {BLACK, WHITE};

class Piece : public QGraphicsPixmapItem //possible memory leak
{
public:
    Piece();
    Piece(int x, int y, Color color);
    int getPosx();
    int getPosy();
    LogicalPiece pieceType;
private:
protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    int x_ = 0;
    int y_ = 0;
    Color color_;
};

#endif // PIECE_H
