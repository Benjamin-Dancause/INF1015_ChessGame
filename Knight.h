#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // KNIGHT_H
