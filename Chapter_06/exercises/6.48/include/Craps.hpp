#include <iostream>
#include <random>
#include <ctime>

class Craps
{
private:
    enum class Status
    {
        CONTINUE,
        WON,
        LOST,
        EXIT
    };

    Status _gameStatus;

    const int MIN{1};
    const int MAX{6};

    int _myPoint;
    int _bankBalance;
    int _wager;

    std::default_random_engine engine;

    int rollDice();
    void setWager();
    void checkScore(int);
    void getStatus();
    int getRandomNumber();

public:
    Craps();
    ~Craps();

    void run();
};
