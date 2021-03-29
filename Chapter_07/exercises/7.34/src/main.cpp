#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>

using namespace std;

const size_t ROWS = 12;
const size_t COLS = 12;
const int MAX_DOTS = 100;

default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randomInt(0, 3);
uniform_int_distribution<unsigned int> randomXPtr(1, ROWS - 2);
uniform_int_distribution<unsigned int> randomYPtr(1, COLS - 2);

enum Direction
{
    DOWN,
    RIGHT,
    UP,
    LEFT
};



void mazeTraversal(char[][COLS], const int, const int, int, int, int);
void mazeGenerator(char[][COLS], int *, int *);
void printMaze(const char[][COLS]);
bool validMove(const char[][COLS], int, int);
bool coordsAreEdge(int, int);

int main(int argc, char const *argv[])
{

    char maze[ROWS][COLS];
    int xStart, yStart, x, y;

    for (size_t r = 0; r < ROWS; ++r)
        for (size_t c = 0; c < COLS; ++c)
            maze[r][c] = '#';

    mazeGenerator(maze, &xStart, &yStart);

    x = xStart;
    y = yStart;

    mazeTraversal(maze, xStart, yStart, x, y, RIGHT);

    return 0;
}

void mazeTraversal(char maze[][COLS], const int xCoord, const int yCoord, int row, int col, int direction)
{
    static bool flag = false;

    maze[row][col] = 'x';

    printMaze(maze);

    if (coordsAreEdge(row, col) && row != xCoord && col != yCoord)
    {
        cout << "\nMaze successfully exited!!\n\n";
        return;
    }
    else if (row == xCoord && col == yCoord && flag)
    {
        cout << "\nArrived back at the starting location.\n\n";
        return;
    }
    else
    {
        flag = true;
        for (int move = direction, count = 0; count < 4; ++count, ++move, move %= 4)
            switch (move)
            {
            case DOWN:
                if (validMove(maze, row + 1, col))
                {
                    mazeTraversal(maze, xCoord, yCoord, row + 1, col, LEFT);
                    return;
                }
                break;
            case RIGHT:
                if (validMove(maze, row, col + 1))
                {
                    mazeTraversal(maze, xCoord, yCoord, row, col + 1, DOWN);
                    return;
                }
                break;
            case UP:
                if (validMove(maze, row - 1, col))
                {
                    mazeTraversal(maze, xCoord, yCoord, row - 1, col, RIGHT);
                    return;
                }
                break;
            case LEFT:
                if (validMove(maze, row, col - 1))
                {
                    mazeTraversal(maze, xCoord, yCoord, row, col - 1, UP);
                    return;
                }
                break;
            }
    }
}

bool validMove(const char maze[][COLS], int r, int c)
{
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] != '#');
}

bool coordsAreEdge(int x, int y)
{
    if ((x == 0 || x == COLS - 1) && (y >= 0 && y <= COLS - 1))
        return true;
    else if ((y == 0 || y == COLS - 1) && (x >= 0 && x <= ROWS - 1))
        return true;
    else
        return false;
}

void printMaze(const char maze[][COLS])
{
    for (size_t x = 0; x < ROWS; ++x)
    {
        for (size_t y = 0; y < COLS; ++y)
            cout << maze[x][y];
        cout << endl;
    }

    cout << "\nHit return to see next move\n";
    cin.get();
}

void mazeGenerator(char maze[][COLS], int *xPtr, int *yPtr)
{
    int a, x, y, entry, exit;

    do
    {
        entry = randomInt(engine);
        exit = randomInt(engine);
    } while (entry == exit);

    if (entry == 0)
    {
        *xPtr = randomXPtr(engine);
        *yPtr = 0;
        maze[*xPtr][0] = '.';
    }
    else if (entry == 1)
    {
        *xPtr = 0;
        *yPtr = randomYPtr(engine);
        maze[0][*yPtr] = '.';
    }
    else if (entry == 2)
    {
        *xPtr = randomXPtr(engine);
        *yPtr = (COLS - 1);
        maze[*xPtr][COLS - 1] = '.';
    }
    else
    {
        *xPtr = ROWS - 1;
        *yPtr = randomYPtr(engine);
        maze[ROWS - 1][*yPtr] = '.';
    }

    if (exit == 0)
    {
        a = randomXPtr(engine);
        maze[a][0] = '.';
    }
    else if (exit == 1)
    {
        a = randomYPtr(engine);
        maze[0][a] = '.';
    }
    else if (exit == 2)
    {
        a = randomXPtr(engine);
        maze[a][COLS - 1] = '.';
    }
    else
    {
        a = randomYPtr(engine);
        maze[ROWS - 1][a] = '.';
    }

    for (size_t loop = 1; loop < MAX_DOTS; ++loop)
    {
        x = randomXPtr(engine);
        y = randomYPtr(engine);
        maze[x][y] = '.';
    }
}