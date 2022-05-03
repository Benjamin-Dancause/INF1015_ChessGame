#include "Rook.h"
#include <iostream>

Rook::Rook(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType_ = BLACK_ROOK;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_rdt60.png"));
    }
    else
    {
        pieceType_ = WHITE_ROOK;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_rlt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Rook::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;

    std::cout << "old x: " << x_ << " old y: " << y_ << std::endl;
    if (color_ == WHITE)
    {
        if (y_ - y > 0 && x_ == x)
        {
            std::cout << "GOING UP" << std::endl;
            bool update = true;
            bool capturing = false;
            for (int i = y_ - 1 ; i > y; i--)
            {
                if (LogicalBoard::getBoard().getPiece(x_,i) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
            }
            if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
            {
                update = false;
                invalideMove();
            }
            else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
            {
                capturing = true;
            }
            if (update)
            {
                if(capturing)
                    capture.hasCaptured(x,y);
                updateBoard(x,y);
            }
        }
        else if (y_ - y < 0 && x_ == x)
        {
            std::cout << "GOING DOWN" << std::endl;
            bool update = true;
            bool capturing = false;
            for (int i = y_ + 1 ; i < y; i++)
            {
                if (LogicalBoard::getBoard().getPiece(x_,i) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
            }
            if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
            {
                update = false;
                invalideMove();
            }
            else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
            {
                capturing = true;
            }
            if (update)
            {
                if(capturing)
                    capture.hasCaptured(x,y);
                updateBoard(x,y);
            }

        }
        else if (x_ - x > 0 && y_ == y)
        {
            std::cout << "GOING LEFT" << std::endl;
            bool update = true;
            bool capturing = false;
            for (int i = x_ - 1 ; i > x; i--)
            {
                if (LogicalBoard::getBoard().getPiece(i,y_) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
            }
            if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
            {
                update = false;
                invalideMove();
            }
            else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
            {
                capturing = true;
            }
            if (update)
            {
                if(capturing)
                    capture.hasCaptured(x,y);
                updateBoard(x,y);
            }
        }
        else if (x_ - x < 0 && y_ == y)
        {
            std::cout << "GOING RIGHT" << std::endl;
            bool update = true;
            bool capturing = false;
            for (int i = x_ + 1 ; i > x; i++)
            {
                if (LogicalBoard::getBoard().getPiece(i,y_) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
            }
            if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
            {
                update = false;
                invalideMove();
            }
            else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
            {
                capturing = true;
            }
            if (update)
            {
                if(capturing)
                    capture.hasCaptured(x,y);
                updateBoard(x,y);
            }
        }
        else if (x_ == x && y_ == y)
        {
            std::cout << "NOTHING HAPPENED" << std::endl;
            updateBoard(x,y);
        }
        else
        {
            invalideMove();
        }
    }
    else
    {
        if (y_ - y > 0 && x_ == x)
        {
            std::cout << "GOING UP" << std::endl;
        }
        else if (y_ - y < 0 && x_ == x)
        {
            std::cout << "GOING DOWN" << std::endl;
        }
        else if (x_ - x > 0 && y_ == y)
        {
            std::cout << "GOING LEFT" << std::endl;
        }
        else if (x_ - x < 0 && y_ == y)
        {
            std::cout << "GOING RIGHT" << std::endl;
        }
        else if (x_ == x && y_ == y)
        {
            std::cout << "NOTHING HAPPENED" << std::endl;
        }
        else
        {
            invalideMove();
        }
    }
    QGraphicsItem::mouseReleaseEvent((e));
}
