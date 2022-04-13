#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // KING_H
