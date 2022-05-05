#include "Board.h"
#include <iostream>


Board::Board(QObject *parent) : QGraphicsScene(parent)
{
    view_ = new QGraphicsView(this);

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
                tiles_.append(tile);
                addItem(tile);
                if (j == 7) {temp = !temp;}
            }
        }
    }

    //construction of the pieces
    for (int i = 0; i < 8; i++)
    {
        Pawn* pawn = new Pawn(i, 1, BLACK);
        pieces_.append(pawn);
        connect(&(pawn->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(pawn);
        LogicalBoard::getBoard().setPiece(i, 1, BLACK_PAWN);
    }

    for (int i = 0; i < 8; i++)
    {
        Pawn* pawn = new Pawn(i, 6, WHITE);
        pieces_.append(pawn);
        connect(&(pawn->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(pawn);
        LogicalBoard::getBoard().setPiece(i, 6, WHITE_PAWN);
    }

    {
        Rook* whiteRook1 = new Rook(0, 7, WHITE);
        pieces_.append(whiteRook1);
        connect(&(whiteRook1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteRook1);
        LogicalBoard::getBoard().setPiece(0, 7, WHITE_ROOK);

        Rook* whiteRook2 = new Rook(7, 7, WHITE);
        pieces_.append(whiteRook2);
        connect(&(whiteRook2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteRook2);
        LogicalBoard::getBoard().setPiece(7, 7, WHITE_ROOK);

        Rook* blackRook1 = new Rook(0, 0, BLACK);
        pieces_.append(blackRook1);
        connect(&(blackRook1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackRook1);
        LogicalBoard::getBoard().setPiece(0, 0, BLACK_ROOK);

        Rook* blackRook2 = new Rook(7, 0, BLACK);
        pieces_.append(blackRook2);
        connect(&(blackRook2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackRook2);
        LogicalBoard::getBoard().setPiece(7, 0, BLACK_ROOK);
    }

    {
        Knight* whiteKnight1 = new Knight(1, 7, WHITE);
        pieces_.append(whiteKnight1);
        connect(&(whiteKnight1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteKnight1);
        LogicalBoard::getBoard().setPiece(1, 7, WHITE_KNIGHT);

        Knight* whiteKnight2 = new Knight(6, 7, WHITE);
        pieces_.append(whiteKnight2);
        connect(&(whiteKnight2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteKnight2);
        LogicalBoard::getBoard().setPiece(6, 7, WHITE_KNIGHT);

        Knight* blackKnight1 = new Knight(1, 0, BLACK);
        pieces_.append(blackKnight1);
        connect(&(blackKnight1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackKnight1);
        LogicalBoard::getBoard().setPiece(1, 0, BLACK_KNIGHT);

        Knight* blackKnight2 = new Knight(6, 0, BLACK);
        pieces_.append(blackKnight2);
        connect(&(blackKnight2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackKnight2);
        LogicalBoard::getBoard().setPiece(6, 0, BLACK_KNIGHT);

    }

    {
        Bishop* whiteBishop1 = new Bishop(2, 7, WHITE);
        pieces_.append(whiteBishop1);
        connect(&(whiteBishop1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteBishop1);
        LogicalBoard::getBoard().setPiece(2, 7, WHITE_BISHOP);

        Bishop* whiteBishop2 = new Bishop(5, 7, WHITE);
        pieces_.append(whiteBishop2);
        connect(&(whiteBishop2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteBishop2);
        LogicalBoard::getBoard().setPiece(5, 7, WHITE_BISHOP);

        Bishop* blackBishop1 = new Bishop(2, 0, BLACK);
        pieces_.append(blackBishop1);
        connect(&(blackBishop1->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackBishop1);
        LogicalBoard::getBoard().setPiece(2, 0, BLACK_BISHOP);

        Bishop* blackBishop2 = new Bishop(5, 0, BLACK);
        pieces_.append(blackBishop2);
        connect(&(blackBishop2->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackBishop2);
        LogicalBoard::getBoard().setPiece(5, 0, BLACK_BISHOP);
    }

    {
        Queen* whiteQueen = new Queen(3, 7, WHITE);
        pieces_.append(whiteQueen);
        connect(&(whiteQueen->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteQueen);
        LogicalBoard::getBoard().setPiece(3, 7, WHITE_QUEEN);

        Queen* blackQueen = new Queen(3, 0, BLACK);
        pieces_.append(blackQueen);
        connect(&(blackQueen->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackQueen);
        LogicalBoard::getBoard().setPiece(3, 0, BLACK_QUEEN);
    }
    
    {
        King* whiteKing = new King(4, 7, WHITE);
        pieces_.append(whiteKing);
        connect(&(whiteKing->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(whiteKing);
        LogicalBoard::getBoard().setPiece(4, 7, WHITE_KING);

        King* blackKing = new King(4, 0, BLACK);
        pieces_.append(blackKing);
        connect(&(blackKing->messenger), &Messenger::hasCaptured, this, &Board::hidePiece);
        addItem(blackKing);
        LogicalBoard::getBoard().setPiece(4, 0, BLACK_KING);
    }

}

Board::~Board()
{
    for (int i = 0; i < pieces_.size(); i++)
    {
        delete pieces_.at(i);
    }

    for (int i = 0 ; i < tiles_.size(); i++)
    {
        delete tiles_.at(i);
    }
}

void Board::hidePiece(int x, int y)
{
    for (int i = 0; i < 32; i++)
    {
        std::cout << i << std::endl;
        if (pieces_[i]->getPosx() == x && pieces_[i]->getPosy() == y)
        {
            std::cout << "got it !" << std::endl;
            pieces_[i]->hide();
            pieces_[i]->gotCaptured();
        }
    }
}


