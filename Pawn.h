#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "LogicalBoard.h"

class Pawn : public Piece
{
public:
    Pawn(int x, int y, Color color);
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
private:
    bool isFirstMove = true;
};

#endif // PAWN_H
