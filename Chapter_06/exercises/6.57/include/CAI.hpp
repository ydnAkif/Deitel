#ifndef CAI_HPP
#define CAI_HPP

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <string>
#include <vector>

#include "Questions.hpp"

class CAI
{
private:
    Questions<int> _iQuestions;
    Questions<double> _dQuestions;

    enum class QuizStates
    {
        INIT,
        PLAY,
        EXIT
    };

    enum class ProblemTypes
    {
        DIVISIONS,
        MULTIPLICATION,
        ADDITION,
        SUBTRACTION
    };

    const int MAX_QUESTIONS{10};

    QuizStates _currentState;
    ProblemTypes _problemType;

    std::vector<std::string> _correctResponses;
    std::vector<std::string> _incorrectResponses;

    int _questionCount;
    int _correct;
    int _incorrect;
    int _difficulty;
    int _randomProblem;

    std::default_random_engine engine;

    template <typename T>
    bool checkAnswer(T answer, T solution)
    {
        return answer == solution;
    }

    void initiliase();
    void setDifficulty();
    void chooseProblemType();
    void setProblemType(int);
    void generateQuestion();
    void askQuestion();
    void printResponse(bool);
    void printReport();
    void reset();
    int getRandomNumber(const int &, const int &);

public:
    CAI();
    ~CAI();
    void run();
};

#endif // CAI_HPP