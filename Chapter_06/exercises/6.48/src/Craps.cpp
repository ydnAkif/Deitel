#include "Craps.hpp"

Craps::Craps() : _gameStatus(Status::CONTINUE), _myPoint(0),
                 _bankBalance(1000), _wager(0), engine(static_cast<int>(time(0))) {}
Craps::~Craps() {}

int Craps::rollDice()
{
    int die1 = getRandomNumber();
    int die2 = getRandomNumber();

    int sum = die1 + die2;

    std::cout << "Player rolled "
              << die1
              << " + "
              << die2
              << " = "
              << sum
              << std::endl;
    return sum;
}

void Craps::setWager()
{
    while (true)
    {
        std::cout << "Enter a wager $0-$"
                  << _bankBalance
                  << " : ";

        std::cin >> _wager;

        if (_wager >= 0 && _wager <= _bankBalance)
        {
            if (_wager == _bankBalance)
            {
                std::cout << std::endl
                          << "*** Look at you going for broke. You brave "
                          << "little fella. ***"
                          << std::endl
                          << std::endl;
            }
            break;
        }
    }
}

void Craps::checkScore(int sum)
{
    switch (sum)
    {
    case 7:
        if (_myPoint > 0)
        {
            _gameStatus = Status::LOST;
            break;
        }
        if (_myPoint > 0 && sum == _myPoint)
        {
            _gameStatus == Status::WON;
            break;
        }

    case 11:
        _gameStatus = Status::WON;
        break;
    case 2:
    case 3:
    case 12:
        _gameStatus = Status::LOST;
        break;
    default:
        _gameStatus = Status::CONTINUE;
        _myPoint = sum;

        std::cout << "> Point is "
                  << _myPoint
                  << std::endl;
        break;
    }
}

void Craps::getStatus()
{
    if (_gameStatus == Status::WON)
    {
        _bankBalance += _wager;

        std::cout << std::endl
                  << "*** Player wins ***"
                  << std::endl;
    }
    else if (_gameStatus == Status::LOST)
    {
        _bankBalance -= _wager;

        std::cout << std::endl
                  << "*** Player lost ***"
                  << std::endl;
    }

    if (_bankBalance == 0)
    {
        std::cout << std::endl
                  << "*** Sorry, You busted! ***"
                  << std::endl;
        _gameStatus = Status::EXIT;
    }

    if (_gameStatus != Status::CONTINUE && _bankBalance > 0)
    {
        std::cout << "Your balance is $"
                  << _bankBalance
                  << std::endl;

        char cont;

        std::cout << std::endl
                  << " Continue (y/n) ? ";
        std::cin >> cont;

        if (cont == 'y')
        {
            _gameStatus = Status::CONTINUE;
            setWager();
        }
        else
        {
            _gameStatus = Status::EXIT;
        }
    }
}

void Craps::run()
{
    setWager();

    while (_gameStatus != Status::EXIT)
    {
        checkScore(rollDice());
        getStatus();
    }
}

int Craps::getRandomNumber()
{
    return std::uniform_int_distribution<int>{MIN, MAX}(engine);
}