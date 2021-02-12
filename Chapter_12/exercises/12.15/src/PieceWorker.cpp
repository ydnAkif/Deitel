#include <iostream>
#include <iomanip>
#include "PieceWorker.hpp"

PieceWorker::PieceWorker(const std::string &first,
                         const std::string &last, const std::string &ssn,
                         double wage, int pieces)
    : Employee(first, last, ssn)
{
    setWage(wage);
    setPieces(pieces);
}

void PieceWorker::setWage(double w)
{
    if (w > 0.0)
        wage = w;
    else
        throw std::invalid_argument("Wage for pieces must be > 0.0");
}

double PieceWorker::getWage() const
{
    return wage;
}

void PieceWorker::setPieces(int p)
{
    if (p > 0.0)
        pieces = p;
    else
        throw std::invalid_argument("Pieces must be > 0.0");
}

int PieceWorker::getPieces() const
{
    return pieces;
}

double PieceWorker::earnings() const
{
    return getPieces() * getWage();
}

void PieceWorker::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "PieceWorker employee: ";
    Employee::print();
    std::cout << "\nwage: " << getWage()
              << "; pieces: " << getPieces();
}