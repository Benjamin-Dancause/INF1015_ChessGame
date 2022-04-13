#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(int x, int y, Color color);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
};

#endif // QUEEN_H
