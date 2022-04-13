#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // PAWN_H
