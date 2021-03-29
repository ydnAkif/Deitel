#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

default_random_engine engine(static_cast<int>(time(0)));

uniform_int_distribution<unsigned int> RandomInt(1, 6);

unsigned int rollDice();

const size_t arraySize = 22;
const int ROLLS = 1000;

int main(int argc, char const *argv[])
{
    enum Status
    {
        CONTINUE,
        WON,
        LOST
    };

    unsigned int sumOfDice, myPoint = 0, length = 0, winSum = 0,
                            loseSum = 0;
    Status gameStatus = CONTINUE;
    size_t roll;
    array<int, arraySize> wins = {};
    array<int, arraySize> losses = {};

    for (unsigned int i = 1; i <= ROLLS; ++i)
    {
        sumOfDice = rollDice();
        roll = 1;

        switch (sumOfDice)
        {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;

        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
        }

        while (CONTINUE == gameStatus)
        {
            sumOfDice = rollDice();
            ++roll;

            if (sumOfDice == myPoint)
                gameStatus = WON;
            else if (7 == sumOfDice)
                gameStatus = LOST;
        }

        if (roll > (arraySize - 1))
            roll = arraySize - 1;

        if (WON == gameStatus)
        {
            ++wins.at(roll);
            ++winSum;
        }
        else
        {
            ++losses.at(roll);
            ++loseSum;
        }
    }

    cout << "Games won or lost after the 20th roll"
         << "\nare displayed as the 21st roll.\n\n";

    for (size_t z = 1; z < arraySize; ++z)
    {
        cout << setw(4) << wins.at(z) << " games won and " << setw(4)
             << losses.at(z) << " games lost on roll" << z << '\n';
    }

    cout << setiosflags(ios::fixed | ios::showpoint)
         << "\nThe chances of winning are " << winSum << " / "
         << winSum + loseSum << " = " << setprecision(2)
         << 100.0 * winSum / (winSum + loseSum) << "%\n";

    for (size_t k = 1; k < arraySize; ++k)
        length += wins.at(k) * k + losses.at(k) * k;
    cout << "The average game length is " << setprecision(2)
         << length / static_cast<double>(ROLLS) << " rolls." << endl;

    return 0;
}

unsigned int rollDice(void)
{
    unsigned int die1, die2, workSum;
    die1 = RandomInt(engine);
    die2 = RandomInt(engine);

    workSum = die1 + die2;

    return workSum;
}
