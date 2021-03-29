#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int rollDice();
int main()
{
    enum Status
    {
        CONTINUE,
        WON,
        LOST
    };

    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0};
    Status gameStatus = Status::CONTINUE;
    unsigned int sumofDice = rollDice();

    switch (sumofDice)
    {
    case 7:
    case 11:
        gameStatus = Status::WON;
        break;
    case 2:
    case 3:
    case 12:
        gameStatus = Status::LOST;
        break;
    default:
        gameStatus = Status::CONTINUE;
        myPoint = sumofDice;
        std::cout << "Point is "
                  << myPoint
                  << std::endl;
        break;
    }

    while (Status::CONTINUE == gameStatus)
    {
        sumofDice = rollDice();

        if (sumofDice == myPoint)
        {
            gameStatus = Status::WON;
        }
        else
        {
            if (sumofDice == 7)
            {
                gameStatus = Status::LOST;
            }
        }
    }

    if (Status::WON == gameStatus)
    {
        std::cout << "Player wins"
                  << std::endl;
    }
    else
    {
        std::cout << "Player lost"
                  << std::endl;
    }

    return 0;
}

unsigned int rollDice()
{
    unsigned int die1 = 1 + rand() % 6;
    unsigned int die2 = 1 + rand() % 6;

    unsigned int sum = die1 + die2;

    std::cout << "Player rolled "
              << die1
              << " + "
              << die2
              << " = "
              << sum
              << std::endl;

    return sum;
}