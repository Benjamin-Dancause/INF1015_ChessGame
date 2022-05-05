#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == WHITE)
    {
        pieceType_ = WHITE_PAWN;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_plt60.png"));
    }
    else
    {
        pieceType_ = BLACK_PAWN;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_pdt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}



void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;
    
    std::cout << "old x: " << x_ << " old y: " << y_ << std::endl;

    if (color_ == WHITE)
    {
        if (LogicalBoard::getBoard().isWhiteTurn())
        {
            if(std::abs(x - x_) == 1 && y - y_ == -1 ) // tried capturing a piece
            {
                std::cout << "tried capturing a piece" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x, y) != NOTHING && LogicalBoard::getBoard().getPiece(x,y) > WHITE_PAWN)
                {
                    messenger.hasCaptured(x, y);
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == -1) // tried going forward by one tile
            {
                std::cout << "tried moving a piece" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x_, y_ - 1) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == -2 && isFirstMove) // tried going forward by two tile
            {
                std::cout << "tried moving the piece by 2" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING && LogicalBoard::getBoard().getPiece(x,y+1) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == 0 && x - x_ == 0)
            {
                std::cout << "did nothing" << std::endl;
                setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
            }
            else
            {
                invalideMove();
            }
        }
        else
        {
            wrongSide();
        }
    }
    else
    {
        if (!LogicalBoard::getBoard().isWhiteTurn())
        {
            if(std::abs(x - x_) == 1 && y - y_ == 1 ) // tried capturing a piece
            {
                std::cout << "tried capturing a piece" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x, y) != NOTHING && LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                {
                    messenger.hasCaptured(x, y);
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == 1) // tried going forward by one tile
            {
                std::cout << "tried moving a piece" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x_, y_ + 1) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == 2 && isFirstMove) // tried going forward by two tile
            {
                std::cout << "tried moving the piece by 2" << std::endl;
                if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING && LogicalBoard::getBoard().getPiece(x,y-1) == NOTHING)
                {
                    updateBoard(x,y);
                    LogicalBoard::getBoard().nextTurn();
                }
                else
                {
                    invalideMove();
                }
            }
            else if (y - y_ == 0 && x - x_ == 0)
            {
                std::cout << "did nothing" << std::endl;
                updateBoard(x,y);
            }
            else
            {
                invalideMove();
            }
        }
        else
        {
            wrongSide();
        }
    }

    std::cout << "x: " << x << " y: " << y << std::endl; //Debug tool, to be remove (remove the #include iostream too)

    if (isFirstMove) {isFirstMove = false;}
    QGraphicsItem::mouseReleaseEvent((e));
}
