#include "Bishop.h"
#include <iostream>


Bishop::Bishop(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == WHITE)
    {
        pieceType_ = WHITE_BISHOP;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_blt60.png"));
    }
    else
    {
        pieceType_ = BLACK_BISHOP;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_bdt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Bishop::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;
    bool goingRight = x > x_;
    bool goingDown = y > y_;
    if (color_ == WHITE)
    {
        if (LogicalBoard::getBoard().isWhiteTurn())
        {
            bool validMove = true;
            if (std::abs(x - x_) != std::abs(y - y_))
            {
                invalideMove();
            }
            else if (x_ == x)
            {
                updateBoard(x,y);
            }
            else if ( goingDown && goingRight )
            {
                for (int i = 1; x_ + i < x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ + i, y_ + i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if ( !goingDown && goingRight)
            {
                for (int i = 1; x_ + i < x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ + i, y_ - i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if (goingDown && !goingRight)
            {
                for (int i = 1; x_ - i > x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ - i, y_ + i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if (!goingDown && !goingRight)
            {
                for (int i = 1; x_ - i > x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ - i, y_ - i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < NOTHING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
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
            bool validMove = true;
            if (x_ == x)
            {
                updateBoard(x,y);
            }
            else if ( goingDown && goingRight )
            {
                for (int i = 1; x_ + i < x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ + i, y_ + i) != NOTHING)
                    {
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if ( !goingDown && goingRight)
            {
                for (int i = 1; x_ + i < x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ + i, y_ - i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if (goingDown && !goingRight)
            {
                for (int i = 1; x_ - i > x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ - i, y_ + i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
            else if (!goingDown && !goingRight)
            {
                for (int i = 1; x_ - i > x ; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(x_ - i, y_ - i) != NOTHING)
                    {
                        std::cout << i << std::endl;
                        invalideMove();
                        validMove = false;
                        break;
                    }

                }
                if (validMove)
                {
                    if (LogicalBoard::getBoard().getPiece(x,y) == NOTHING)
                    {
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else
                    {
                        messenger.hasCaptured(x,y);
                        updateBoard(x,y);
                        LogicalBoard::getBoard().nextTurn();
                    }
                }
            }
        }
        else
        {
            wrongSide();
        }
    }
    QGraphicsItem::mouseReleaseEvent((e));
}
