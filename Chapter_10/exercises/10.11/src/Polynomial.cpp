#include <iostream>
#include <iomanip>
#include "Polynomial.hpp"

Polynomial::Polynomial()
{
    for (int t = 0; t < maxTerms; t++)
    {
        coefficients[t] = 0;
        exponents[t] = 0;
    }
    numberOfTerms = 0;
}

void Polynomial::printPolynomial(void) const
{
    int start;
    bool zero = false;

    if (coefficients[0])
    {
        std::cout << coefficients[0];
        start = 1;
        zero = true;
    }
    else
    {
        if (coefficients[1])
        {
            std::cout << coefficients[1] << 'x';

            if ((exponents[1] != 0) && (exponents[1] != 1))
            {
                std::cout << '^' << exponents[1];
            }

            zero = true;
        }

        start = 2;
    }

    for (int x = start; x < maxTerms; x++)
    {
        if (coefficients[x] != 0)
        {
            std::cout << std::showpos << coefficients[x]
                      << std::noshowpos << 'x';

            if ((exponents[x] != 0) && (exponents[x] != 1))
            {
                std::cout << '^' << exponents[x];
            }

            zero = true;
        }
    }

    if (!zero)
    {
        std::cout << '0';
    }

    std::cout << std::endl;
}

const Polynomial Polynomial::operator=(const Polynomial &r)
{
    exponents[0] = r.exponents[0];
    coefficients[0] = r.coefficients[0];

    for (int s = 1; s < maxTerms; s++)
    {
        if (r.exponents[s] != 0)
        {
            exponents[s] = r.exponents[s];
            coefficients[s] = r.coefficients[s];
        }
        else
        {
            exponents[s] = 0;
            coefficients[s] = 0;
        }
    }

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &r) const
{
    Polynomial temp;
    bool exponentExists;
    int s;

    temp.coefficients[0] = coefficients[0] + r.coefficients[0];

    for (s = 1; (s < maxTerms) && (r.exponents[s] != 0); s++)
    {
        temp.coefficients[s] = r.coefficients[s];
        temp.exponents[s] = r.exponents[s];
    }

    for (int x = 1; x < maxTerms; x++)
    {
        exponentExists = false;

        for (int t = 1; (t < maxTerms) && (!exponentExists); t++)
        {
            if (exponents[x] == temp.exponents[t])
            {
                temp.coefficients[t] += coefficients[x];
                exponentExists = true;
            }
        }

        if (!exponentExists)
        {
            temp.exponents[s] = exponents[x];
            temp.coefficients[s] += coefficients[x];
            s++;
        }
    }

    return temp;
}

Polynomial &Polynomial::operator+=(const Polynomial &r)
{
    *this = *this + r;
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial &r) const
{
    Polynomial temp;
    bool exponentExists;
    int s;

    temp.coefficients[0] = coefficients[0] - r.coefficients[0];

    for (s = 1; (s < maxTerms) && (exponents[s] != 0); s++)
    {
        temp.coefficients[s] = coefficients[s];
        temp.exponents[s] = exponents[s];
    }

    for (int x = 1; x < maxTerms; x++)
    {
        exponentExists = false;

        for (int t = 1; (t < maxTerms) && (!exponentExists); t++)
        {
            if (r.exponents[x] == temp.exponents[t])
            {
                temp.coefficients[t] -= r.coefficients[x];
                exponentExists = true;
            }
        }

        if (!exponentExists)
        {
            temp.exponents[s] = r.exponents[x];
            temp.coefficients[s] -= r.coefficients[x];
            s++;
        }
    }

    return temp;
}

Polynomial &Polynomial::operator-=(const Polynomial &r)
{
    *this = *this - r;
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial &r)
{
    Polynomial temp;
    int s = 1;

    for (int x = 0; (x < maxTerms) && (x == 0 || coefficients[x] != 0); x++)
        for (int y = 0; (y < maxTerms) && (y == 0 || r.coefficients[y] != 0); y++)
            if (coefficients[x] * r.coefficients[y])
                if ((exponents[x] == 0) && (r.exponents[y] == 0))
                {
                    temp.coefficients[0] += coefficients[x] * r.coefficients[y];
                }
                else
                {
                    temp.coefficients[s] = coefficients[x] * r.coefficients[y];
                    temp.exponents[s] = exponents[x] + r.exponents[y];
                    s++;
                }

    polynomialCombine(temp);
    return temp;
}

void Polynomial::polynomialCombine(Polynomial &w)
{
    Polynomial temp = w;
    int exp;

    for (int x = 0; x < maxTerms; x++)
    {
        w.coefficients[x] = 0;
        w.exponents[x] = 0;
    }

    for (int x = 1; x < maxTerms; x++)
    {
        exp = temp.exponents[x];

        for (int y = x + 1; y < maxTerms; y++)
            if ((exp == temp.exponents[y]) && (exp != 0))
            {
                temp.coefficients[x] += temp.coefficients[y];
                temp.exponents[y] = 0;
                temp.coefficients[y] = 0;
            }
    }

    w = temp;
}

Polynomial &Polynomial::operator*=(const Polynomial &r)
{
    *this = *this * r;
    return *this;
}

void Polynomial::enterTerms(void)
{
    bool found = false;
    int c, e, term;

    std::cout << std::endl
              << "Enter number of polynomial terms: ";
    std::cin >> numberOfTerms;

    for (int n = 1; n <= numberOfTerms; n++)
    {
        std::cout << std::endl
                  << "Enter coefficient: ";
        std::cin >> c;
        std::cout << "Enter exponent: ";
        std::cin >> e;

        if (c != 0)
        {
            if (e == 0)
            {
                coefficients[0] += c;
                continue;
            }

            for (term = 1; (term < maxTerms) && (coefficients[term] != 0); term++)
                if (e == exponents[term])
                {
                    coefficients[term] += c;
                    exponents[term] = e;
                    found = true;
                }

            if (!found)
            {
                coefficients[term] += c;
                exponents[term] = e;
            }
        }
    }
}

int Polynomial::getNumberOfTerms()
{
    return numberOfTerms;
}

int Polynomial::getTermExponent(int term)
{
    return exponents[term];
}

int Polynomial::getTermCoefficients(int term)
{
    return coefficients[term];
}

void Polynomial::setCoefficients(int term, int coefficient)
{
    if (coefficients[term] == 0)
    {
        std::cout << "No term at this location, can not set term." << std::endl;
    }
    else
    {
        coefficients[term] = coefficient;
    }
}

Polynomial::~Polynomial()
{
}