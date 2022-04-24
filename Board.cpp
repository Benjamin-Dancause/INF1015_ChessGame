#include "Board.h"
#include <iostream>


Board::Board(QObject *parent) : QGraphicsScene(parent)
{
    view = new QGraphicsView(this);
    //construction of the grid
    for (int i = 0 ; i < 9; i++)
    {
        addLine(0, i * 75, 600, i * 75);
        addLine(i * 75, 0, i * 75, 600);
    }
    //construction of the black and white patern
    {
        bool temp = true;
        for (int i = 0 ; i < 8; i++)
        {
             for (int j = 0 ; j < 8 ; j++)
            {
                Tile* tile = new Tile();
                tile->setPos(j * 75, i * 75);
                if (temp)
                {
                    if (j % 2 == 0) {tile->setWhite();}
                }
                else
                {
                    if (j % 2 == 1) {tile->setWhite();}
                }
                tiles.append(tile);
                addItem(tile);
                if (j == 7) {temp = !temp;}
            }
        }
    }

    //construction of the pieces
    for (int i = 0 ; i < 4; i++)
    {
        Piece* piece = new Piece();
        piece->setPos(i*75, 0);
        pieces.append(piece);
        addItem(piece);
    }

    //testing an allegedly better way to do the pieces
    QPixmap image("/home/Cherry/Documents/inf1015/projet/INF1015_ChessGame/Black/Chess_bdt60.png");
    QPixmap image1("../INF1015_ChessGame/Black/Chess_bdt60.png");

    std::cout << image.isNull() << std::endl;
    std::cout << image1.isNull() << std::endl;
    QGraphicsPixmapItem* test = new QGraphicsPixmapItem(image);
    addItem(test);



}

Board::~Board()
{
    for (int i = 0; i < pieces.size(); i++)
    {
        delete pieces.at(i);
    }

    for (int i = 0 ; i < tiles.size(); i++)
    {
        delete tiles.at(i);
    }
}


