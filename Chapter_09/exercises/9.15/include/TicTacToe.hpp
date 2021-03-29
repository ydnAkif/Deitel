#ifndef TIC_TAC_TOC_HPP
#define TIC_TAC_TOC_HPP
#include <array>

class TicTacToe
{
private:
    enum Status
    {
        WIN,
        DRAW,
        CONTINUE
    };

    std::array<std::array<int,3>,3> board;

public:
    TicTacToe();
    ~TicTacToe();
    void makeMove();
    void printBoard();
    bool validMove(int, int);
    bool xoMove(int);
    Status gameStatus();
};

#endif