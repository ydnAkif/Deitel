#include <iostream>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>

using namespace std;

default_random_engine engine(static_cast<int>(time(0)));

uniform_int_distribution<unsigned int> RandomInt(1, 6);

int rollDice();

const size_t arraySize = 22;
const int ROLLS = 1000;

int main(int argc, char const *argv[])
{
    enum Outcome
    {
        CONTINUE,
        WIN,
        LOSE
    };

    int gameStatus, sum, myPoint, length = 0, winSum = 0,
                                  loseSum = 0;
    size_t roll;
    array<int, arraySize> wins = {};
    array<int, arraySize> losses = {};

    for (unsigned int i = 1; i <= ROLLS; ++i)
    {
        sum = rollDice();
        roll = 1;

        switch (sum)
        {
        case 7:
        case 11:
            gameStatus = WIN;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOSE;
            break;

        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            break;
        }

        while (CONTINUE == gameStatus)
        {
            sum = rollDice();
            ++roll;

            if (sum == myPoint)
                gameStatus = WIN;
            else if (sum == 7)
                gameStatus = LOSE;
        }

        if (roll > (arraySize - 1))
            roll = arraySize - 1;

        if (gameStatus == WIN)
        {
            ++wins[roll];
            ++winSum;
        }
        else
        {
            ++losses[roll];
            ++loseSum;
        }
    }

    cout << "Games won or lost after the 20th roll"
         << "\nare displayed as the 21st roll.\n\n";

    for (size_t z = 1; z < arraySize; ++z)
    {
        cout << setw(4) << wins[z] << " games won and " << setw(4)
             << losses[z] << " games lost on roll" << z << '\n';
    }

    cout << setiosflags(ios::fixed | ios::showpoint)
         << "\nThe chances of winning are " << winSum << " / "
         << winSum + loseSum << " = " << setprecision(2)
         << 100.0 * winSum / (winSum + loseSum) << "%\n";

    for (size_t k = 1; k < arraySize; ++k)
        length += wins[k] * k + losses[k] * k;
    cout << "The average game length is " << setprecision(2)
         << length / static_cast<double>(ROLLS) << " rolls." << endl;

    return 0;
}

int rollDice(void)
{
    int die1, die2, workSum;
    die1 = RandomInt(engine);
    die2 = RandomInt(engine);

    workSum = die1 + die2;

    return workSum;
}
