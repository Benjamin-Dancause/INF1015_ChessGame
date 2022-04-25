#include "Board.h"
#include <iostream>


Board::Board(QObject *parent) : QGraphicsScene(parent)
{
    view = new QGraphicsView(this);

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
        Pawn* pawn = new Pawn(i, 1, BLACK);
        pieces.append(pawn);
        addItem(pawn);
        //LogicalBoard::getBoard().setPiece(i, 1, BLACK_PAWN);
    }

    for (int i = 0; i < 8; i++)
    {
        Pawn* pawn = new Pawn(i, 6, WHITE);
        pieces.append(pawn);
        addItem(pawn);
        LogicalBoard::getBoard().setPiece(i, 6, BLACK_PAWN);
    }

    {
        Rook* whiteRook1 = new Rook(0, 7, WHITE);
        pieces.append(whiteRook1);
        addItem(whiteRook1);
        LogicalBoard::getBoard().setPiece(0, 7, WHITE_ROOK);

        Rook* whiteRook2 = new Rook(7, 7, WHITE);
        pieces.append(whiteRook2);
        addItem(whiteRook2);
        LogicalBoard::getBoard().setPiece(7, 7, WHITE_ROOK);

        Rook* blackRook1 = new Rook(0, 0, BLACK);
        pieces.append(blackRook1);
        addItem(blackRook1);
        LogicalBoard::getBoard().setPiece(0, 0, BLACK_ROOK);

        Rook* blackRook2 = new Rook(7, 0, BLACK);
        pieces.append(blackRook2);
        addItem(blackRook2);
        LogicalBoard::getBoard().setPiece(7, 0, BLACK_ROOK);
    }

    {
        Knight* whiteKnight1 = new Knight(1, 7, WHITE);
        pieces.append(whiteKnight1);
        addItem(whiteKnight1);
        LogicalBoard::getBoard().setPiece(1, 7, WHITE_KNIGHT);

        Knight* whiteKnight2 = new Knight(6, 7, WHITE);
        pieces.append(whiteKnight2);
        addItem(whiteKnight2);
        LogicalBoard::getBoard().setPiece(6, 7, WHITE_KNIGHT);

        Knight* blackKnight1 = new Knight(1, 0, BLACK);
        pieces.append(blackKnight1);
        addItem(blackKnight1);
        LogicalBoard::getBoard().setPiece(1, 0, BLACK_KNIGHT);

        Knight* blackKnight2 = new Knight(6, 0, BLACK);
        pieces.append(blackKnight2);
        addItem(blackKnight2);
        LogicalBoard::getBoard().setPiece(6, 0, BLACK_KNIGHT);

    }

    {
        Bishop* whiteBishop1 = new Bishop(2, 7, WHITE);
        pieces.append(whiteBishop1);
        addItem(whiteBishop1);
        LogicalBoard::getBoard().setPiece(2, 7, WHITE_BISHOP);

        Bishop* whiteBishop2 = new Bishop(5, 7, WHITE);
        pieces.append(whiteBishop2);
        addItem(whiteBishop2);
        LogicalBoard::getBoard().setPiece(5, 7, WHITE_BISHOP);

        Bishop* blackBishop1 = new Bishop(2, 0, BLACK);
        pieces.append(blackBishop1);
        addItem(blackBishop1);
        LogicalBoard::getBoard().setPiece(2, 0, BLACK_BISHOP);

        Bishop* blackBishop2 = new Bishop(5, 0, BLACK);
        pieces.append(blackBishop2);
        addItem(blackBishop2);
        LogicalBoard::getBoard().setPiece(5, 0, BLACK_BISHOP);
    }

    {
        Queen* whiteQueen = new Queen(3, 7, WHITE);
        pieces.append(whiteQueen);
        addItem(whiteQueen);
        LogicalBoard::getBoard().setPiece(3, 7, WHITE_QUEEN);

        Queen* blackQueen = new Queen(3, 0, BLACK);
        pieces.append(blackQueen);
        addItem(blackQueen);
        LogicalBoard::getBoard().setPiece(3, 0, BLACK_QUEEN);
    }
    
    {
        King* whiteKing = new King(4, 7, WHITE);
        pieces.append(whiteKing);
        addItem(whiteKing);
        LogicalBoard::getBoard().setPiece(4, 7, WHITE_KING);

        King* blackKing = new King(4, 0, BLACK);
        pieces.append(blackKing);
        addItem(blackKing);
        LogicalBoard::getBoard().setPiece(4, 0, BLACK_KING);
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


