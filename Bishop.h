#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(int x, int y, Color color);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;
};

#endif // BISHOP_H
