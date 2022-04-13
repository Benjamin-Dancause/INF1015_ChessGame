#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(int x, int y, Color color);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // PAWN_H
