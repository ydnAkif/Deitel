#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

int rollDice();

static int totalRolls = 36000;
const static size_t arraySize = 13;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<unsigned int> randomInt(1, 6);

int main()
{

    /*

    Expected rolls

    1+1 = 2
    2+1,1+2 = 3
    2+2,3+1,1+3 = 4
    1+4,4+1,2+3,3+2 = 5
    1+5,5+1,2+4,4+2,3+3 = 6
    1+6,6+1,2+5,5+2,3+4,4+3 =7
    2+6,6+2,3+5,5+3,4+4 = 8
    3+6,6+3,4+5,5+4 = 9
    4+6,6+4,5+5 = 10
    5+6,6+5 = 11
    6+6 = 12
    
    */
    array<int, arraySize> expected = {0, 0, 1, 2, 3, 4,
                                      5, 6, 5, 4, 3, 2, 1};

    array<int, arraySize> tally = {};

    cout << "Program to print the totals of 2 dice rolls 36000 times"
         << endl
         << endl;
    for (unsigned int i = 0; i < totalRolls; ++i)
    {
        ++tally[rollDice() + rollDice()];
    }

    cout << setw(10) << "Sum" << setw(10) << "Total" << setw(10)
         << "Expected" << setw(10) << "Actual" << endl
         << setiosflags(ios::fixed | ios::showpoint);

    for (size_t i = 2; i < arraySize; ++i)
    {
        cout << setw(10) << i << setw(10) << tally[i] << setprecision(3)
             << setw(9) << 100.0 * expected[i] / 36 << "%" << setprecision(3)
             << setw(9) << 100.0 * tally[i] / totalRolls << "%" << endl;
    }

    return 0;
}

int rollDice()
{
    return randomInt(engine);
}