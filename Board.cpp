#include "Board.h"
#include <iostream>


Board::Board(QObject *parent) : QGraphicsScene(parent)
{
    view = new QGraphicsView(this);
    //construction of the grid // might not be usefull ????????????
    for (int i = 0 ; i < 9; i++)
    {
        addLine(0, i * tile_size, 600, i * tile_size);
        addLine(i * tile_size, 0, i * tile_size, 600);
    }
    //construction of the black and white pattern
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
    for (int i = 0; i < 8; i++)
    {
        Pawn* pawn = new Pawn(i * tile_size + 7, 1 * tile_size + 7, BLACK);
        pieces.append(pawn);
        addItem(pawn);
        LogicalBoard::getBoard().setPiece(i, 1, PAWN);
    }

    for (int i = 0; i < 8; i++)
    {
        Pawn* pawn = new Pawn(i * tile_size + 7, 6 * tile_size + 7, WHITE);
        pieces.append(pawn);
        addItem(pawn);
        LogicalBoard::getBoard().setPiece(i, 6, PAWN);
    }

    {
        Rook* whiteRook1 = new Rook(tile_size * 7 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteRook1);
        addItem(whiteRook1);
        LogicalBoard::getBoard().setPiece(7, 7, ROOK);

        Rook* whiteRook2 = new Rook(7,tile_size * 7 + 7, WHITE);
        pieces.append(whiteRook2);
        addItem(whiteRook2);
        LogicalBoard::getBoard().setPiece(0, 7, ROOK);

        Rook* blackRook1 = new Rook(7,7, BLACK);
        pieces.append(blackRook1);
        addItem(blackRook1);
        LogicalBoard::getBoard().setPiece(7, 0, ROOK);

        Rook* blackRook2 = new Rook(tile_size * 7 + 7, 7, BLACK);
        pieces.append(blackRook2);
        addItem(blackRook2);
        LogicalBoard::getBoard().setPiece(0, 0, ROOK);
    }

    {
        Knight* whiteKnight1 = new Knight(tile_size + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteKnight1);
        addItem(whiteKnight1);
        LogicalBoard::getBoard().setPiece(1, 7, KNIGHT);

        Knight* whiteKnight2 = new Knight(tile_size * 6 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteKnight2);
        addItem(whiteKnight2);
        LogicalBoard::getBoard().setPiece(6, 7, KNIGHT);

        Knight* blackKnight1 = new Knight(tile_size + 7, 7, BLACK);
        pieces.append(blackKnight1);
        addItem(blackKnight1);
        LogicalBoard::getBoard().setPiece(1, 0, KNIGHT);

        Knight* blackKnight2 = new Knight(tile_size * 6 + 7, 7, BLACK);
        pieces.append(blackKnight2);
        addItem(blackKnight2);
        LogicalBoard::getBoard().setPiece(6, 0, KNIGHT);

    }

    {
        Bishop* whiteBishop1 = new Bishop(tile_size * 2 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteBishop1);
        addItem(whiteBishop1);
        LogicalBoard::getBoard().setPiece(2, 7, BISHOP);

        Bishop* whiteBishop2 = new Bishop(tile_size * 5 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteBishop2);
        addItem(whiteBishop2);
        LogicalBoard::getBoard().setPiece(5, 7, BISHOP);

        Bishop* blackBishop1 = new Bishop(tile_size * 2 + 7, 7, BLACK);
        pieces.append(blackBishop1);
        addItem(blackBishop1);
        LogicalBoard::getBoard().setPiece(2, 0, BISHOP);

        Bishop* blackBishop2 = new Bishop(tile_size * 5 + 7, 7, BLACK);
        pieces.append(blackBishop2);
        addItem(blackBishop2);
        LogicalBoard::getBoard().setPiece(5, 0, BISHOP);
    }

    {
        Queen* whiteQueen = new Queen(tile_size * 3 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteQueen);
        addItem(whiteQueen);
        LogicalBoard::getBoard().setPiece(3, 7, QUEEN);

        Queen* blackQueen = new Queen(tile_size * 3 + 7, 7, BLACK);
        pieces.append(blackQueen);
        addItem(blackQueen);
        LogicalBoard::getBoard().setPiece(3, 0, QUEEN);
    }
    
    {
        King* whiteKing = new King(tile_size * 4 + 7, tile_size * 7 + 7, WHITE);
        pieces.append(whiteKing);
        addItem(whiteKing);
        LogicalBoard::getBoard().setPiece(4, 7, KING);

        King* blackKing = new King(tile_size * 4 + 7, 7, BLACK);
        pieces.append(blackKing);
        addItem(blackKing);
        LogicalBoard::getBoard().setPiece(4, 0, KING);
    }


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


