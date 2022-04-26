#include "Piece.h"
#include <iostream>

Piece::Piece()
{
    setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

Piece::Piece(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_blt60.png"));
    }

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;
    QMessageBox msg;
    msg.setText("Illegal move");
    std::cout << "x: " << x / tile_size << " y: " << y / tile_size << std::endl; //Debug tool, to be removed
    msg.exec();
    setPos(x + piece_adjust, y + piece_adjust);

    QGraphicsItem::mouseReleaseEvent((e));
}

void Piece::invalideMove()
{
    QMessageBox msg;
    msg.setText("Invalid move");
    msg.exec();
    setPos(x_ * tile_size + piece_adjust, y_ * tile_size + piece_adjust);
}

void Piece::updateBoard(int x, int y)
{
    LogicalBoard::getBoard().setPiece(x_, y_, NOTHING);
    LogicalBoard::getBoard().setPiece(x, y, pieceType_);
    x_ = x;
    y_ = y;
    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}
