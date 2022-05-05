#include "Queen.h"
#include <iostream>

Queen::Queen(int x, int y, Color color)
{
    x_ = x;
    y_ = y;
    color_ = color;
    if (color == BLACK)
    {
        pieceType_ = BLACK_QUEEN;
        setPixmap(QPixmap("../INF1015_ChessGame/Black/Chess_qdt60.png"));
    }
    else
    {
        pieceType_ = WHITE_QUEEN;
        setPixmap(QPixmap("../INF1015_ChessGame/White/Chess_qlt60.png"));
    }

    setPos(x * tile_size + piece_adjust, y * tile_size + piece_adjust);
}

void Queen::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    int x = ((pos().x() + tile_size / 2) - ((int) pos().x() + tile_size / 2 ) % tile_size) / tile_size;
    int y = ((pos().y() + tile_size / 2) - ((int) pos().y() + tile_size / 2 ) % tile_size) / tile_size;
    if (x_ == x && y_ == y)
    {
        updateBoard(x,y);
    }
    else if (std::abs(x_ - x) == std::abs(y_ - y))
    {
        bool goingRight = x > x_;
        bool goingDown = y > y_;
        if (std::abs(x - x_) != std::abs(y - y_))
        {
            invalideMove();
        }
        else if (color_ == WHITE)
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
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
                    }
                    else
                    {
                        updateBoard(x,y);
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
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
                    }
                    else
                    {
                        updateBoard(x,y);
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
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
                    }
                    else
                    {
                        updateBoard(x,y);
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
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
                    }
                    else
                    {
                        updateBoard(x,y);
                    }
                }
            }
        }
        else
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
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
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
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
                    {
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
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
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else
                    {
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);
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
                    }
                    else if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING)
                    {
                        invalideMove();
                    }
                    else
                    {
                        capture.hasCaptured(x,y);
                        updateBoard(x,y);;
                    }
                }
            }
        }
    }
    else if (x_ == x || y_ == y)
    {
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
                        break;
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
                        break;
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
                if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING && LogicalBoard::getBoard().getPiece(x,y) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
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
                if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING && LogicalBoard::getBoard().getPiece(x,y) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
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
                    if (LogicalBoard::getBoard().getPiece(i, y_) != NOTHING)
                    {
                        update = false;
                        invalideMove();
                    }
                }
                if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING && LogicalBoard::getBoard().getPiece(x,y) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
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
                for (int i = x_ + 1 ; i < x; i++)
                {
                    if (LogicalBoard::getBoard().getPiece(i, y_) != NOTHING)
                    {
                        update = false;
                        invalideMove();
                    }
                }
                if (LogicalBoard::getBoard().getPiece(x,y) >= BLACK_KING && LogicalBoard::getBoard().getPiece(x,y) != NOTHING)
                {
                    update = false;
                    invalideMove();
                }
                else if (LogicalBoard::getBoard().getPiece(x,y) < BLACK_KING)
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
    }
    else
    {
        invalideMove();
    }

    QGraphicsItem::mouseReleaseEvent((e));
}
