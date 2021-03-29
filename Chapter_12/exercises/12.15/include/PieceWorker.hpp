#ifndef PIECE_WORKER_HPP
#define PIECE_WORKER_HPP

#include <string>
#include "Employee.hpp"

class PieceWorker : public Employee
{
private:
    double wage;
    int pieces;

public:
    PieceWorker(const std::string &, const std::string &, const std::string &,
                double, int);
    virtual ~PieceWorker() {}

    void setWage(double);
    double getWage() const;
    void setPieces(int);
    int getPieces() const;

    virtual double earnings() const override;
    virtual void print() const override;
};

#endif