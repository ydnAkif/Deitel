#include <iostream>
#include <string>
#include <array>

using namespace std;

enum Direction
{
    DOWN,
    RIGHT,
    UP,
    LEFT
};

const size_t SIZE = 12;
const int X_START = 2, Y_START = 0;

void mazeTraversal(char[][SIZE], int, int, int);
void printMaze(const char[][SIZE]);
bool validMove(const char[][SIZE], int, int);
bool coordsAreEdge(int, int);

int main(int argc, char const *argv[])
{
    char maze[SIZE][SIZE] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                             {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
                             {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
                             {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
                             {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
                             {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                             {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                             {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
                             {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
                             {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
                             {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
                             {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
    mazeTraversal(maze, X_START, Y_START, RIGHT);

    return 0;
}

void mazeTraversal(char maze[][SIZE], int xCoord, int yCoord, int direction)
{
    static bool flag = false;
    maze[xCoord][yCoord] = 'x';
    printMaze(maze);

    if (coordsAreEdge(xCoord, yCoord) && xCoord != X_START && yCoord != Y_START)
    {
        cout << "\nMaze successfully exited!!\n\n";
        return;
    }
    else if (xCoord == X_START && yCoord == Y_START && flag)
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
                if (validMove(maze, xCoord + 1, yCoord))
                {
                    mazeTraversal(maze, xCoord + 1, yCoord, LEFT);
                    return;
                }
                break;
            case RIGHT:
                if (validMove(maze, xCoord, yCoord + 1))
                {
                    mazeTraversal(maze, xCoord, yCoord + 1, DOWN);
                    return;
                }
                break;
            case UP:
                if (validMove(maze, xCoord - 1, yCoord))
                {
                    mazeTraversal(maze, xCoord - 1, yCoord, RIGHT);
                    return;
                }
                break;
            case LEFT:
                if (validMove(maze, xCoord, yCoord - 1))
                {
                    mazeTraversal(maze, xCoord, yCoord - 1, UP);
                    return;
                }
                break;
            }
    }
}

bool validMove(const char maze[][SIZE], int r, int c)
{
    return (r >= 0 && r < SIZE && c >= 0 && c < SIZE && maze[r][c] != '#');
}

bool coordsAreEdge(int x, int y)
{
    if ((x == 0 || x == SIZE - 1) && (y >= 0 && y <= SIZE - 1))
        return true;
    else if ((y == 0 || y == SIZE - 1) && (x >= 0 && x <= SIZE - 1))
        return true;
    else
        return false;
}

void printMaze(const char maze[][SIZE])
{
    for (size_t x = 0; x < SIZE; ++x)
    {
        for (size_t y = 0; y < SIZE; ++y)
            cout << maze[x][y];
        cout << endl;
    }

    cout << "\nHit return to see next move\n";
    cin.get();
}