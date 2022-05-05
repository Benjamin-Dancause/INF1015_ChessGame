#ifndef PIECE_H
#define PIECE_H

#ifndef tile_size
#define tile_size 75
#endif

#ifndef piece_adjust
#define piece_adjust 7
#endif

#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <cstdlib>
#include "LogicalBoard.h"
#include "Messenger.h"

enum Color {BLACK, WHITE};

class Piece : public QGraphicsPixmapItem
{
public:
    Piece();
    Piece(int x, int y, Color color);
    int getPosx();
    int getPosy();
    void invalideMove();
    void wrongSide();
    void updateBoard(int x, int y);
    void gotCaptured();
    Messenger messenger;
private:
protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    int x_ = 0;
    int y_ = 0;
    Color color_;
    LogicalPiece pieceType_;
    bool captured = false;
};

#endif // PIECE_H
