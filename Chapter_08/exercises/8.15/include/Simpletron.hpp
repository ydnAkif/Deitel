#ifndef SIMPLETRON_HPP
#define SIMPLETRON_HPP

#include <iostream>

class Simpletron
{
private:
    const int SIZE = 100;
    const int MAX_WORD = 9999;
    const int MIN_WORD = -9999;
    const long SENTINEL = -99999;

    enum Commands
    {
        READ = 10,
        WRITE = 11,
        LOAD = 20,
        STORE = 21,
        ADD = 30,
        SUBTRACT = 31,
        DIVISION = 32,
        MULTIPLY = 33,
        BRANCH = 40,
        BRANCHNEG = 41,
        BRANCZERO = 42,
        HALT = 43
    };

    int memory[100] = {0};
    int accumulator = 0;
    int instructionCounter = 0;
    int opCode = 0;
    int operand = 0;
    int instructionRegister = 0;

public:
    Simpletron();
    ~Simpletron();

    void load(int *const);
    void execute(int *const, int *const, int *const, int *const, int *const, int *const);
    void dump(const int *const, int, int, int, int, int);
    bool validWord(int);
    void output(const char *const, int, int, bool);
    void run();
};

#endif // SIMPLETRON_HPP
