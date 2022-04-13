#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // ROOK_H
