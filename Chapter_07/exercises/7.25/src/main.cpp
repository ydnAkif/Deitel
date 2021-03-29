#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randomInt(0, 7);

const size_t SIZE = 8;

bool queenCheck(const array<array<char, SIZE>, SIZE>, int, int);
void placeQueens(array<array<char, SIZE>, SIZE> &);
void printBoard(const array<array<char, SIZE>, SIZE>);
void xConflictSquares(array<array<char, SIZE>, SIZE> &, int, int);
void xDiagonals(array<array<char, SIZE>, SIZE> &, int, int);
bool avaibleSquare(const array<array<char, SIZE>, SIZE>);

inline int validMove(const array<array<char, SIZE>, SIZE> board, int row, int column)
{
    return (row >= 0 && row < SIZE && column >= 0 && column < SIZE);
}

int main(int argc, char const *argv[])
{
    array<array<char, SIZE>, SIZE> board = {};
    placeQueens(board);
    printBoard(board);

    return 0;
}

bool queenCheck(const array<array<char, SIZE>, SIZE> board, int row, int column)
{
    int r = row, c = column;

    for (size_t d = 0; d < SIZE; ++d)
        if (board[row][d] == 'Q' || board[d][column] == 'Q')
            return false;

    for (size_t e = 0; e < SIZE && validMove(board, --r, --c); ++e)
        if (board[r][c] == 'Q')
            return false;

    r = row;
    c = column;
    for (size_t f = 0; f < SIZE && validMove(board, --r, ++c); ++f)
        if (board[r][c] == 'Q')
            return false;

    r = row;
    c = column;
    for (size_t g = 0; g < SIZE && validMove(board, ++r, --c); ++g)
        if (board[r][c] == 'Q')
            return false;

    r = row;
    c = column;
    for (size_t h = 0; h < SIZE && validMove(board, ++r, ++c); ++h)
        if (board[r][c] == 'Q')
            return false;

    return true;
}
void placeQueens(array<array<char, SIZE>, SIZE> &board)
{
    const char QUEEN = 'Q';
    int rowMove, columnMove, queens = 0;
    bool done = false;

    while (queens < SIZE && !done)
    {
        rowMove = randomInt(engine);
        columnMove = randomInt(engine);

        if (queenCheck(board, rowMove, columnMove))
        {
            board[rowMove][columnMove] = QUEEN;
            xConflictSquares(board, rowMove, columnMove);
            ++queens;
        }
        done = avaibleSquare(board);
    }
}
void printBoard(const array<array<char, SIZE>, SIZE> board)
{
    int queens = 0;

    cout << setw(3) << '0' << setw(2) << '1' << setw(3) << '2'
         << setw(2) << '3' << setw(2) << '4' << setw(3) << '5'
         << setw(2) << '6' << setw(2) << '7' << endl;

    for (int r = 0; r < SIZE; ++r)
    {
        cout << setw(2) << r << ' ';
        for (int c = 0; c < SIZE; ++c)
        {
            cout << board[r][c] << ' ';
            if (board[r][c] == 'Q')
                ++queens;
        }

        cout << endl;
    }

    if (queens == 8)
        cout << "\nEight Queens were placed on the board! " << endl;
    else
        cout << endl
             << queens << " Queens were placed on the board!" << endl;
}
void xConflictSquares(array<array<char, SIZE>, SIZE> &board, int row, int column)
{
    for (size_t loop = 0; loop < SIZE; ++loop)
    {
        if (board[row][loop] == '\0')
            board[row][loop] = '*';
        if (board[loop][column] == '\0')
            board[loop][column] = '*';
    }

    xDiagonals(board, row, column);
}
void xDiagonals(array<array<char, SIZE>, SIZE> &board, int row, int column)
{
    int r = row, c = column;

    for (size_t a = 0; a < SIZE && validMove(board, --r, --c); ++a)
        board[r][c] = '*';

    r = row;
    c = column;
    for (size_t b = 0; b < SIZE && validMove(board, --r, ++c); ++b)
        board[r][c] = '*';

    r = row;
    c = column;
    for (size_t d = 0; d < SIZE && validMove(board, ++r, --c); ++d)
        board[r][c] = '*';

    r = row;
    c = column;
    for (size_t e = 0; e < SIZE && validMove(board, ++r, ++c); ++e)
        board[r][c] = '*';
}
bool avaibleSquare(const array<array<char, SIZE>, SIZE> board)
{

    for (size_t row = 0; row < SIZE; ++row)
        for (size_t column = 0; column < SIZE; ++column)
            if (board[row][column] == '\0')
                return false;
    return true;
}