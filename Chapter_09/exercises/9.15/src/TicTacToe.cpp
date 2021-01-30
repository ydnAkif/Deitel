#include <iostream>
#include <iomanip>
#include "TicTacToe.hpp"

TicTacToe::TicTacToe()
{
    for (int j = 0; j < 3; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            board[j][k] = ' ';
        }
    }
}

TicTacToe::~TicTacToe() {}

void TicTacToe::makeMove()
{
    printBoard();

    while (true)
    {
        if (xoMove('X'))
        {
            break;
        }
        else if (xoMove('O'))
        {
            break;
        }
    }
}

void TicTacToe::printBoard()
{
    std::cout << "  0    1    2\n\n";
    for (int r = 0; r < 3; ++r)
    {
        std::cout << r;

        for (int c = 0; c < 3; ++c)
        {
            std::cout << std::setw(3) << static_cast<char>(board[r][c]);

            if (c != 2)
            {
                std::cout << "  |";
            }
        }

        if (r != 2)
        {
            std::cout << "\n  ____|_____|____";
            std::cout << "\n      |     |    \n";
        }
    }

    std::cout << "\n\n";
}

bool TicTacToe::validMove(int r, int c)
{
    return r >= 0 && r < 3 && c >= 0 && c < 3 && board[r][c] == ' ';
}

bool TicTacToe::xoMove(int symbol)
{
    int x, y;

    do
    {
        std::cout << "Player " << static_cast<char>(symbol) << " enter move: ";
        std::cin >> x >> y;
        std::cout << '\n';
    } while (!validMove(x, y));

    board[x][y] = symbol;
    printBoard();
    Status xoStatus = gameStatus();
    if (xoStatus == Status::WIN)
    {
        std::cout << "Player " << static_cast<char>(symbol) << " wins!\n";
        return true;
    }
    else if (xoStatus == Status::DRAW)
    {
        std::cout << "Game is a draw.\n";
        return true;
    }
    else
        return false;
}

TicTacToe::Status TicTacToe::gameStatus()
{
    int a;

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return Status::WIN;
    }
    else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
    {
        return Status::WIN;
    }

    for (a = 0; a < 3; ++a)
    {
        if (board[a][0] != ' ' && board[a][0] == board[a][1] && board[a][0] == board[a][2])
        {
            return Status::WIN;
        }
    }

    for (a = 0; a < 3; ++a)
    {
        if (board[0][a] != ' ' && board[0][a] == board[1][a] && board[0][a] == board[2][a])
        {
            return Status::WIN;
        }
    }

    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            if (board[r][c] == ' ')
            {
                return Status::CONTINUE;
            }
        }
    }

    return Status::DRAW;
}