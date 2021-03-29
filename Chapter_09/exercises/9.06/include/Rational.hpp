#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational
{
private:
    int numerator;
    int denominator;
    void reduction(void);

public:
    explicit Rational(int = 0, int = 1); //default constructor
    ~Rational();
    Rational addition(const Rational &);
    Rational subtraction(const Rational &);
    Rational multiplication(const Rational &);
    Rational division(const Rational &);
    void printRational(void) const;
    void printRationalAsDouble(void) const;
};

#endif