#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen();
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // QUEEN_H
