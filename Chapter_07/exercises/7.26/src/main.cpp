#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

const size_t SIZE = 8;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randomInt(0, SIZE - 1);

void clearBoard(array<array<int, SIZE>, SIZE>);

void printBoard(const array<array<int, SIZE>, SIZE>);

bool validMove(int, int, const array<array<int, SIZE>, SIZE>);

int main(int argc, char *argv[])
{
    array<array<int, SIZE>, SIZE> board = {};
    int firstMoveRow, firstMoveColumn;
    array<array<int, SIZE>, SIZE> access = {2, 3, 4, 4, 4, 4, 3, 2,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            2, 3, 4, 4, 4, 4, 3, 2};
    int currentRow, currentColumn, moveNumber = 0, accessNumber;
    int testRow, testColumn, minRow, minColumn, minAccess = 9;

    array<int, SIZE> horizantal = {2, 1, -1, -2, -2, -1, 1, 2};
    array<int, SIZE> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};

    bool done, closedTour = false;

    clearBoard(board);
    currentRow = randomInt(engine);
    currentColumn = randomInt(engine);
    firstMoveRow = currentRow;
    firstMoveColumn = currentColumn;
    board[currentRow][currentColumn] = ++moveNumber;

    done = false;

    while (!done)
    {
        accessNumber = minAccess;

        for (size_t moveType = 0; moveType < SIZE; ++moveType)
        {
            testRow = currentRow + vertical[moveType];
            testColumn = currentColumn + horizantal[moveType];

            if (validMove(testRow, testColumn, board))
            {
                if (access[testRow][testColumn] < accessNumber)
                {
                    accessNumber = access[testRow][testColumn];
                    minRow = testRow;
                    minColumn = testColumn;
                }

                --access[testRow][testColumn];
            }
        }

        if (accessNumber == minAccess)
        {
            done = true;
        }
        else
        {
            currentRow = minRow;
            currentColumn = minColumn;
            board[currentRow][currentColumn] = ++moveNumber;

            if (moveNumber == 64)
            {
                for (size_t m = 0; m < SIZE; ++m)
                {
                    testRow = currentRow + vertical[m];
                    testRow = currentColumn + horizantal[m];

                    if (testRow == firstMoveRow && testColumn == firstMoveColumn)
                        closedTour = true;
                }
            }
        }
    }
    cout << "The tour ended with " << moveNumber << " moves.\n";

    if (moveNumber == 64 && closedTour == true)
        cout << "This was a Closed tour!\n\n";
    else if (moveNumber == 64)
        cout << "This was a full tour!\n\n";
    else
        cout << "This was not a full tour!\n\n";

    cout << "The board for this test is: \n\n";

    printBoard(board);
    return 0;
}

void clearBoard(array<array<int, SIZE>, SIZE> workBoard)
{
    for (size_t row = 0; row < SIZE; ++row)
        for (size_t col = 0; col < SIZE; ++col)
            workBoard[row][col] = 0;
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
        cout << '\n';
    }

    cout << endl;
}

bool validMove(int row, int column, const array<array<int, SIZE>, SIZE> workBoard)
{
    return (row >= 0 && row < SIZE && column >= 0 && column < SIZE && workBoard[row][column] == 0);
}