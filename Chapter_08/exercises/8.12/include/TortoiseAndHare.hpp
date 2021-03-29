#include <iostream>
#include <random>
#include <ctime>
#include <string>

struct participant
{
    std::string name;
    unsigned int position;

    participant() : position(1) {}
};

enum class GameStates
{
    PLAY,
    EXIT
};

class TortoiseAndHare
{
private:
    static const size_t COURSE_LIMIT = 70;
    std::mt19937 gen;
    participant _tortoise;
    participant _hare;

    GameStates _gameState;

    void initialise();
    void moveTortoise(participant &);
    void moveHare(participant &);
    bool isWinner(participant &);
    void printProgress();
    void summarise();
    void reset();
    int getRandomNumber();

public:
    TortoiseAndHare();
    ~TortoiseAndHare();
    void go();
};
