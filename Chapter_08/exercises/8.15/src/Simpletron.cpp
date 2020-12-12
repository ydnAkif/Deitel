#include <iomanip>
#include <iostream>
#include "Simpletron.hpp"

Simpletron::Simpletron()
{
}

Simpletron::~Simpletron()
{
}

void Simpletron::load(int *const loadMemory)
{
    long instruction;
    int i = 0;

    std::cout << "***           Welcome to Simpletron           ***\n"
              << "*** Please enter your program one instruction ***\n"
              << "*** (or data word) at a time. I will type the ***\n"
              << "*** location number and a question mark (?). ***\n"
              << "*** You then type the word for that location. ***\n"
              << "*** Type the sentinel -99999 to stop entering ***\n"
              << "*** your program. ***\n"
              << "00 ? ";
    std::cin >> instruction;

    while (instruction != SENTINEL)
    {
        if (!validWord(instruction))
            std::cout << "Number out of range. Please enter again.\n";
        else
            loadMemory[i++] = instruction;
        std::cout << std::setw(2) << std::setfill('0') << i << " ? ";
        std::cin >> instruction;
    }
}

void Simpletron::execute(int *const memory, int *const acPtr, int *const icPtr,
                         int *const irPtr, int *const opCodePtr, int *const opPtr)
{
    bool fatal = false;
    int temp;
    const char *messages[] = {"Accumulator overflow ***",
                              "Attempt to divide by zero ***",
                              "Invalid opcode detected ***"};
    const char *termString = "\n*** Simpletron execution abnormally terminated ***";
    const char *fatalString = "*** FATAL ERROR: ";

    std::cout << "\n************START SIMPLETRON EXECUTION************\n\n";

    do
    {
        *irPtr = memory[*icPtr];
        *opCodePtr = *irPtr / 100;
        *opPtr = *irPtr % 100;

        switch (*opCodePtr)
        {
        case READ:
            std::cout << "Enter an integer: ";
            std::cin >> temp;

            while (!validWord(temp))
            {
                std::cout << "Number out of range. Please enter again: ";
                std::cin >> temp;
            }

            memory[*opPtr] = temp;
            ++(*icPtr);
            break;

        case WRITE:
            std::cout << "Contents of " << std::setw(2) << std::setfill('0') << *opPtr
                      << ": " << memory[*opPtr] << '\n';
            ++(*icPtr);
            break;

        case LOAD:
            *acPtr = memory[*opPtr];
            ++(*icPtr);
            break;

        case STORE:
            memory[*opPtr] = *acPtr;
            ++(*icPtr);
            break;

        case ADD:
            temp = *acPtr + memory[*opPtr];

            if (!validWord(temp))
            {
                std::cout << fatalString << messages[0] << termString << '\n';
                fatal = true;
            }
            else
            {
                *acPtr = temp;
                ++(*icPtr);
            }
            break;

        case SUBTRACT:
            temp = *acPtr - memory[*opPtr];

            if (!validWord(temp))
            {
                std::cout << fatalString << messages[0] << termString << '\n';
                fatal = true;
            }
            else
            {
                *acPtr = temp;
                ++(*icPtr);
            }
            break;

        case DIVISION:

            if (memory[*opPtr] == 0)
            {
                std::cout << fatalString << messages[1] << termString << '\n';
                fatal = true;
            }
            else
            {
                *acPtr /= memory[*opPtr];
                ++(*icPtr);
            }
            break;

        case MULTIPLY:
            temp = *acPtr * memory[*opPtr];

            if (!validWord(temp))
            {
                std::cout << fatalString << messages[0] << termString << '\n';
                fatal = true;
            }
            else
            {
                *acPtr = temp;
                ++(*icPtr);
            }
            break;

        case BRANCH:
            *icPtr = *opPtr;
            break;

        case BRANCHNEG:
            *acPtr < 0 ? *icPtr = *opPtr : ++(*icPtr);
            break;

        case BRANCZERO:
            *acPtr == 0 ? *icPtr = *opPtr : ++(*icPtr);
            break;

        case HALT:
            std::cout << "*** Simpletron execution terminated ***\n";
            break;

        default:
            std::cout << fatalString << messages[2] << termString << '\n';
            fatal = true;
            break;
        }

    } while (*opCodePtr != HALT && !fatal);

    std::cout << "\n*************END SIMPLETRON EXECUTION*************\n";
}

void Simpletron::dump(const int *const memory, int accumulator, int instructionCounter,
                      int instructionRegister, int operationCode, int operand)
{
    std::cout << "\nREGISTERS:\n";
    output("accumulator", 5, accumulator, true);
    output("instructionCounter", 2, instructionCounter, false);
    output("instructionRegister", 5, instructionRegister, true);
    output("operationCode", 2, operationCode, false);
    output("operand", 2, operand, false);
    std::cout << "\n\nMEMORY:\n";

    int i = 0;
    std::cout << std::setfill(' ') << std::setw(3) << ' ';

    for (; i <= 9; ++i)
        std::cout << std::setw(5) << i << ' ';

    for (i = 0; i < SIZE; ++i)
    {
        if (i % 10 == 0)
            std::cout << '\n'
                      << std::setw(2) << i << ' ';
        std::cout << std::setiosflags(std::ios::internal | std::ios::showpos)
                  << std::setw(5) << std::setfill('0') << memory[i] << ' '
                  << std::resetiosflags(std::ios::internal | std::ios::showpos);
    }
    std::cout << std::endl;
}

bool Simpletron::validWord(int word)
{
    return word >= MIN_WORD && word <= MAX_WORD;
}

void Simpletron::output(const char *const sPtr, int width, int value, bool sign)
{
    std::cout << std::setfill(' ') << std::setiosflags(std::ios::left) << std::setw(20)
              << sPtr << ' ';

    if (sign)
        std::cout << std::setiosflags(std::ios::showpos | std::ios::internal);

    std::cout << std::resetiosflags(std::ios::left) << std::setfill('0');

    if (width == 5)
        std::cout << std::setw(width) << value << '\n';
    else
        std::cout << std::setfill(' ') << std::setw(3) << ' ' << std::setw(width)
                  << std::setfill('0') << value << '\n';
    if (sign)
        std::cout << std::resetiosflags(std::ios::showpos | std::ios::internal);
}

void Simpletron::run()
{
    load(memory);
    execute(memory, &accumulator, &instructionCounter, &instructionRegister, &opCode, &operand);
    dump(memory, accumulator, instructionCounter, instructionRegister, opCode, operand);
}