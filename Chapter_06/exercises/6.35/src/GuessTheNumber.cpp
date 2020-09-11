#include <random>
#include "GuessTheNumber.hpp"

GuessTheNumber::GuessTheNumber() : engine(static_cast<int>(time(0)))
{
    initialise();
}

GuessTheNumber::~GuessTheNumber() {}

void GuessTheNumber::initialise()
{
    _currentState = GameStates::PLAY;

    _randNumber = getRandomNumber();

    _numGuesses = 0;
    _playerGuess = 0;

    std::cout << "I have a number between "
              << MIN
              << " and "
              << MAX
              << std::endl;
}

GameStates GuessTheNumber::guess(int playerGuess)
{
    ++_numGuesses;

    if (playerGuess == _randNumber)
    {
        std::cout << "Excellent! You guessed the number!"
                  << std::endl;
        return GameStates::WON;
    }

    std::cout << "Too "
              << ((playerGuess < _randNumber) ? "low" : "high")
              << ". Try again."
              << std::endl;
    return GameStates::PLAY;
}

int GuessTheNumber::getRandomNumber()
{
    return std::uniform_int_distribution<int>{MIN, MAX}(engine);
}

void GuessTheNumber::run()
{
    while (_currentState != GameStates::EXIT)
    {
        if (_currentState == GameStates::PLAY)
        {
            std::cout << std::endl
                      << "Can you guess my number?"
                      << std::endl
                      << "Please type your guess: ";
            std::cin >> _playerGuess;

            if (_playerGuess < MIN || _playerGuess > MAX)
            {
                std::cout << std::endl
                          << "Invalid guess. Your number needs to be between "
                          << MIN
                          << " and "
                          << MAX
                          << std::endl;
            }

            _currentState = guess(_playerGuess);
        }

        if (_currentState == GameStates::WON)
        {
            victoryMessage();
            std::cout << std::endl
                      << "Would you like to play again (y or n) ? ";
            std::cin >> _playerContinue;

            if (_playerContinue == 'y')
            {
                initialise();
            }
            else
            {
                _currentState = GameStates::EXIT;
            }
        }
    }
}

void GuessTheNumber::victoryMessage() const
{
    if (_numGuesses == 10)
    {
        std::cout << std ::endl
                  << "Guesses: "
                  << _numGuesses
                  << std::endl
                  << "Ahah! You know the secret!"
                  << std::endl;
    }
    else if (_numGuesses < 10)
    {
        std::cout << std ::endl
                  << "Guesses: "
                  << _numGuesses
                  << std::endl
                  << "Either you know the secret or you got lucky!"
                  << std::endl;
    }
    else
    {
        std::cout << std ::endl
                  << "Guesses: "
                  << _numGuesses
                  << std::endl
                  << "You should be able to do better!"
                  << std::endl;
    }
}