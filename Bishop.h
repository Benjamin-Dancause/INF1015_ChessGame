#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // BISHOP_H
