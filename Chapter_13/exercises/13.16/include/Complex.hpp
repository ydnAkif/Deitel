#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
    friend std::ostream &operator<<(std::ostream &, Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);

private:
    int real;
    int imaginary;

public:
    Complex();
};



#endif