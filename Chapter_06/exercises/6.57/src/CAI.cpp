#include "CAI.hpp"

CAI::CAI() : _questionCount(0),
             _correct(0),
             _incorrect(0),
             _difficulty(0),
             _randomProblem(0),
             engine(static_cast<int>(time(0)))
{
    initiliase();
}

CAI::~CAI()
{
    _correctResponses.clear();
    _incorrectResponses.clear();
}

void CAI::initiliase()
{
    _currentState = QuizStates::INIT;

    _correctResponses.push_back("\\(^-^)/ Very good!");
    _correctResponses.push_back("Excellent!");
    _correctResponses.push_back("Nice work!");
    _correctResponses.push_back("Keep up the good work!");
    _incorrectResponses.push_back("No. Please try again.");
    _incorrectResponses.push_back("Wrong. Try once more.");
    _incorrectResponses.push_back("Don't give up!");
    _incorrectResponses.push_back("No. Keep trying.");
}

void CAI::setDifficulty()
{
    int choice{0};

    while (choice == 0)
    {
        std::cout << "Welcome to the quiz."
                  << std::endl
                  << "Please select your difficulty level: "
                  << std::endl
                  << "1. Super mega easy."
                  << std::endl
                  << "2. Normal"
                  << std::endl
                  << "3. Insane"
                  << std::endl
                  << "4. Genius Mode"
                  << std::endl
                  << "> ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            _currentState = QuizStates::PLAY;
            _difficulty = choice;
        }
        else
        {
            choice = 0;
        }
    }
}

void CAI::chooseProblemType()
{
    int choice{0};

    while (choice == 0)
    {
        std::cout << "Please select the type of problems to solve:"
                  << std::endl
                  << "1. Addition."
                  << std::endl
                  << "2. Subtraction."
                  << std::endl
                  << "3. Multiplication."
                  << std::endl
                  << "4. Division."
                  << std::endl
                  << "5. Randomised."
                  << std::endl
                  << "> ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            setProblemType(choice);
        }
        else
        {
            choice = 0;
        }
    }
}

void CAI::setProblemType(int type)
{
    switch (type)
    {
    case 1:
        _problemType = ProblemTypes::ADDITION;
        break;
    case 2:
        _problemType = ProblemTypes::SUBTRACTION;
        break;
    case 3:
        _problemType = ProblemTypes::MULTIPLICATION;
        break;
    case 4:
        _problemType = ProblemTypes::DIVISIONS;
        break;
    case 5:
        _randomProblem = 1;
        break;
    default:
        break;
    }
}

void CAI::generateQuestion()
{
    static int limit[5] = {0, 9, 99, 999, 9999};

    if (_problemType == ProblemTypes::DIVISIONS)
    {
        _dQuestions.init(getRandomNumber(1, limit[_difficulty]), getRandomNumber(1, limit[_difficulty]));
    }
    else
    {
        _iQuestions.init(getRandomNumber(0, limit[_difficulty]), getRandomNumber(0, limit[_difficulty]));
    }
}

void CAI::askQuestion()
{
    int iSolution{0};
    double dSolution{0.0f};
    bool correct;

    std::string questionOperator;

    ++_questionCount;

    if (_randomProblem == 1)
    {
        setProblemType(getRandomNumber(1, 4));
    }

    generateQuestion();

    switch (_problemType)
    {
    case ProblemTypes::ADDITION:
        questionOperator = " + ";
        iSolution = _iQuestions.add();
        break;

    case ProblemTypes::SUBTRACTION:
        questionOperator = " - ";
        iSolution = _iQuestions.subtract();
        break;

    case ProblemTypes::MULTIPLICATION:
        questionOperator = " * ";
        iSolution = _iQuestions.multiply();
        break;

    case ProblemTypes::DIVISIONS:
        questionOperator = " / ";
        dSolution = _dQuestions.divide();
        break;

    default:
        break;
    }

    std::cout << std::endl
              << _questionCount
              << "/"
              << MAX_QUESTIONS
              << " : ";
    if (_problemType == ProblemTypes::DIVISIONS)
    {
        double dAnswer;

        std::cout << _dQuestions.num1
                  << questionOperator
                  << _dQuestions.num2 << " ? ";

        std::cin >> dAnswer;

        while (std::cin.fail())
        {
            std::cout << _dQuestions.num1
                      << questionOperator
                      << _dQuestions.num2 << " ? ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> dAnswer;
        }

        correct = checkAnswer(dAnswer, dSolution);
    }
    else
    {
        int iAnswer;

        std::cout << _iQuestions.num1
                  << questionOperator
                  << _iQuestions.num2 << " ? ";

        std::cin >> iAnswer;

        while (std::cin.fail())
        {
            std::cout << _iQuestions.num1
                      << questionOperator
                      << _iQuestions.num2 << " ? ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> iAnswer;
        }

        correct = checkAnswer(iAnswer, iSolution);
    }

    printResponse(correct);

    (correct) ? ++_correct : ++_incorrect;
}

void CAI::printResponse(bool correct)
{

    if (correct)
    {
        std::cout << std::endl
                  << "\t*** "
                  << _correctResponses[getRandomNumber(0, _correctResponses.size() - 1)]
                  << " ***"
                  << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "\t*** "
                  << _incorrectResponses[getRandomNumber(0, _incorrectResponses.size() - 1)]
                  << " ***"
                  << std::endl;
    }
}

void CAI::printReport()
{
    double percent = (static_cast<double>(_correct) / static_cast<double>(MAX_QUESTIONS)) * 100;

    std::cout << std::endl
              << "You scored "
              << percent
              << "%"
              << std::endl;
    if (percent < 75.0f)
    {
        std::cout << std::endl
                  << "*** Please ask your teacher for extra help. ***"
                  << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "*** (/.__.)/\\(.__.\\) Congratulations, you are ready "
                  << "to go on to the next level! ***"
                  << std::endl;
    }
}

void CAI::reset()
{
    _questionCount = 0;
    _correct = 0;
    _incorrect = 0;
    _difficulty = 0;
    _randomProblem = 0;

    _currentState = QuizStates::INIT;
    srand(static_cast<int>(time(0)));
}

int CAI::getRandomNumber(const int &min, const int &max)
{
    return std::uniform_int_distribution<int>{min, max}(engine);
}

void CAI::run()
{
    char cont;

    while (_currentState != QuizStates::EXIT)
    {
        if (_questionCount == 0)
        {
            setDifficulty();
            chooseProblemType();
        }

        askQuestion();

        if (_questionCount == MAX_QUESTIONS)
        {
            printReport();

            std::cout << std::endl
                      << "Play again ( y / n )? ";
            std::cin >> cont;

            if (cont == 'y')
            {
                reset();
            }
            else
            {
                _currentState = QuizStates::EXIT;
            }
        }
    }
}
