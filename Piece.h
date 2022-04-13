#ifndef PIECE_H
#define PIECE_H

#ifndef tile_size
#define tile_size 75
#endif

#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>

enum Color {BLACK, WHITE};

class Piece : public QGraphicsRectItem //possible memory leak
{
public:
    Piece();
    Piece(int x, int y, Color color);
private:
protected:
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    int x_ = 0;
    int y_ = 0;
    Color color_;
};

#endif // PIECE_H
