#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

int rollDice();

static int totalRolls = 36000;
const static size_t total = 13;

default_random_engine engine(static_cast<int>(time(0)));
uniform_int_distribution<unsigned int> randomInt(1, 6);

int main()
{
    array<int, total> expected = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    array<int, total> tally = {};

    cout << "Program to print the totals of 2 dice rolls 36000 times\n"
         << endl;
    for (unsigned int i = 0; i < totalRolls; ++i)
    {
        ++tally[rollDice() + rollDice()];
    }

    cout << setw(10) << "Sum" << setw(10) << "Total" << setw(10)
         << "Expected" << setw(10) << "Actual" << endl
         << setiosflags(ios::fixed | ios::showpoint);

    for (size_t i = 2; i < expected.size(); ++i)
    {
        cout << setw(10) << i << setw(10) << tally[i] << setprecision(3)
             << setw(9) << 100.0 * expected[i] / 36 << "%" << setprecision(3)
             << setw(9) << 100.0 * tally[i] / 36000 << "%" << endl;
    }

    return 0;
}

int rollDice()
{
    return randomInt(engine);
}