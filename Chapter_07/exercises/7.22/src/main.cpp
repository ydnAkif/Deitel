#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<int> randomInt(0, 7);

const size_t SIZE = 8; // 8x8

void clearBoard(array<array<int, SIZE>, SIZE> &);
void printBoard(const array<array<int, SIZE>, SIZE> );
bool validMove(int, int, const array<array<int, SIZE>, SIZE> );

int main(int argc, char const *argv[])
{
    array<array<int, SIZE>, SIZE> board;
    int currentRow, currentColumn, moveNumber = 0;
    array<array<int, SIZE>, SIZE> access = {2, 3, 4, 4, 4, 4, 3, 2,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            4, 6, 8, 8, 8, 8, 6, 4,
                                            3, 4, 6, 6, 6, 6, 4, 3,
                                            2, 3, 4, 4, 4, 4, 3, 2};

    int testRow, testColumn, minRow, minColumn, minAccess = 9, accessNumber;

    const array<int, SIZE> horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
    const array<int, SIZE> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};

    bool isDone;

    clearBoard(board);
    currentRow = randomInt(engine);
    currentColumn = randomInt(engine);

    board[currentRow][currentColumn] = ++moveNumber;
    isDone = false;

    while (!isDone)
    {
        accessNumber = minAccess;
        for (size_t moveType = 0; moveType < SIZE; ++moveType)
        {
            testRow = currentRow + vertical[moveType];
            testColumn = currentColumn + horizontal[moveType];

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
            isDone = true;
        }
        else
        {
            currentRow = minRow;
            currentColumn = minColumn;
            board[currentRow][currentColumn] = ++moveNumber;
        }
    }

    cout << "The tour ended with " << moveNumber << " moves. \n";

    if (moveNumber == 64)
        cout << "This was a full tour!\n\n";
    else
        cout << "This was not a full tour.\n\n";

    cout << "The board for this test is: \n\n";
    printBoard(board);

    return 0;
}

void clearBoard(array<array<int, SIZE>, SIZE> &board)
{
    for (size_t row = 0; row < SIZE; ++row)
    {
        for (size_t col = 0; col < SIZE; ++col)
        {
            board[row][col] = 0;
        }
    }
}

void printBoard(const array<array<int, SIZE>, SIZE> board)
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
            cout << setw(3) << board[row][col];
        cout << '\n';
    }

    cout << endl;
}

bool validMove(int row, int col, const array<array<int, SIZE>, SIZE> board)
{
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == 0);
}
