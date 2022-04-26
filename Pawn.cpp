#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == WHITE)
    {
        pieceType = WHITE_PAWN;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_plt60.png"));
    }
    else
    {
        pieceType = BLACK_PAWN;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_pdt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}



void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;

    if (color_ == WHITE)
    {

        if(std::abs(x / tile_size - x_) == 1 && y / tile_size - y_ == -1 ) //tried capturing a piece
        {
            std::cout << "tried capturing a piece" << std::endl;
            if (LogicalBoard::getBoard().getPiece(x / tile_size, y / tile_size))
            {
                LogicalBoard::getBoard().setPiece(x_, y_, NOTHING);
                //LogicalBoard::getBoard().setPiece();
            }
        }
        else if (y / tile_size - y_ == -1)
        {
            std::cout << "tried moving a piece" << std::endl;
        }
        else if (y / tile_size - y_ == -2 && isFirstMove)
        {
            std::cout << "tried moving the pawn by 2" << std::endl;
        }
        else
        {
            std::cout << "tried something weird" << std::endl;
            QMessageBox msg;
            msg.setText("Invalid move");
            msg.exec();
        }
    }
    else
    {

    }

    std::cout << "old x: " << x_ << " old y: " << y_ << std::endl;
    std::cout << "x: " << x / tile_size << " y: " << y / tile_size << std::endl; //Debug tool, to be remove (remove the #include iostream too)
    setPos(x + piece_adjust, y + piece_adjust);
    if (isFirstMove) {isFirstMove = false;}
    QGraphicsItem::mouseReleaseEvent((e));
}
