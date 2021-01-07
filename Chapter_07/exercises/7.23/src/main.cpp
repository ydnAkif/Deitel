#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

const size_t SIZE = 8;

default_random_engine engine(static_cast<int>(time(0)));

uniform_int_distribution<int> randomInt(0, SIZE - 1);

bool isValidMove(int, int, const array<array<int, SIZE>, SIZE>);

void printBoard(const array<array<int, SIZE>, SIZE>);

int main(int argc, char const *argv[])
{
    array<array<int, SIZE>, SIZE> board = {};
    int currentRow, currentColumn, moveType, moveNumber = 0, testRow, testColumn;
    array<int, SIZE> horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
    array<int, SIZE> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};
    bool done, goodMove;

    currentRow = randomInt(engine);
    currentColumn = randomInt(engine);
    board[currentRow][currentColumn] = ++moveNumber;
    done = false;

    while (!done)
    {
        moveType = randomInt(engine);
        testRow = currentRow + vertical[moveType];
        testColumn = currentColumn + horizontal[moveType];
        goodMove = isValidMove(testRow, testColumn, board);

        if (goodMove)
        {
            currentRow = testRow;
            currentColumn = testColumn;
            board[currentRow][currentColumn] = ++moveNumber;
        }
        else
        {
            for (unsigned int count = 0; count < SIZE - 1 && !goodMove; ++count)
            {
                moveType = ++moveType % SIZE;
                testRow = currentRow + vertical[moveType];
                testColumn = currentColumn + horizontal[moveType];

                goodMove = isValidMove(testRow, testColumn, board);

                if (goodMove)
                {
                    currentRow = testRow;
                    currentColumn = testColumn;
                    board[currentRow][currentColumn] = ++moveNumber;
                }
            }
            if (!goodMove)
                done = true;
        }
        if (moveNumber == 64)
            done = true;
    }

    cout << "The tour has ended with " << moveNumber << " moves.\n";

    if (moveNumber == 64)
        cout << "This was a full tour!\n";
    else
        cout << "This was not a full tour.\n";

    cout << "The board for this random test was:\n\n";
    printBoard(board);
    return 0;
}

bool isValidMove(int row, int column, const array<array<int, SIZE>, SIZE> workBoard)
{
    return (row >= 0 && row < SIZE && column >= 0 && column < SIZE && workBoard[row][column] == 0);
}

void printBoard(const array<array<int, SIZE>, SIZE> workBoard)
{
    cout << setw(4) << '0' << setw(3) << '1'
         << setw(3) << '2' << setw(3) << '3'
         << setw(3) << '4' << setw(3) << '5'
         << setw(3) << '6' << setw(3) << '7'
         << endl;
    for (size_t row = 0; row < SIZE; ++row)
    {
        cout << row;
        for (size_t col = 0; col < SIZE; ++col)
            cout << setw(3) << workBoard[row][col];
        cout << endl;
    }
    cout << endl;
}