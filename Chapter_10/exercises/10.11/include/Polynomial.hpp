#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

class Polynomial
{

public:
    static const int maxTerms = 8;

    Polynomial();

    Polynomial operator+(const Polynomial &) const;
    Polynomial operator-(const Polynomial &) const;
    Polynomial operator*(const Polynomial &);

    const Polynomial operator=(const Polynomial &);
    Polynomial &operator+=(const Polynomial &);
    Polynomial &operator-=(const Polynomial &);
    Polynomial &operator*=(const Polynomial &);

    void enterTerms();
    void printPolynomial() const;
    int getNumberOfTerms();
    int getTermExponent(int);
    int getTermCoefficients(int);
    void setCoefficients(int, int);
    ~Polynomial();

private:
    int numberOfTerms;
    int exponents[maxTerms];
    int coefficients[maxTerms];
    void polynomialCombine(Polynomial &);
};

#endif