#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_pdt60.png"));
    }
    else
    {
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_plt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}



void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

    int x = (pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size;
    int y = (pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size;

    if (color_ == WHITE)
    {
        if (isFirstMove)
        {
            if(std::abs(x / tile_size - x_) == 1 && y / tile_size - y_ ); //tried capturing a piece
            {
            }
        }
        else
        {

        }
    }



    QMessageBox msg;
    msg.setText("Illegal move");
    std::cout << "x: " << x / tile_size << " y: " << y / tile_size << std::endl; //Debug tool, to be remove (remove the #include iostream too)
    for (int i = 0; i< 8;i++)
        for (int j = 0; j<8 ;j++)
        {
    {
        std::cout << LogicalBoard::getBoard().getPiece(i,j) << std::endl;
    }
        }
    msg.exec();
    setPos(x + piece_adjust, y + piece_adjust);
    if (isFirstMove) {isFirstMove = false;}
    QGraphicsItem::mouseReleaseEvent((e));
}
