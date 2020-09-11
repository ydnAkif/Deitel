#pragma once

#include <iostream>
#include <random>
#include <ctime>

enum class GameStates
{
    PLAY,
    EXIT,
    WON
};

class GuessTheNumber
{
private:
    GameStates _currentState;

    const int MIN{0};
    const int MAX{1000};

    int _randNumber;
    int _playerGuess;
    char _playerContinue;

    std::default_random_engine engine;

    void initialise();
    GameStates guess(int) const;
    int getRandomNumber();

public:
    GuessTheNumber();
    ~GuessTheNumber();

    void run();
};
