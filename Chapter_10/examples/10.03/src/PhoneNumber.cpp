#include <iomanip>
#include "PhoneNumber.hpp"

std::ostream &operator<<(std::ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ") "
           << number.exchange << "-" << number.line;
    return output;
}

std::istream &operator>>(std::istream &input, PhoneNumber &number)
{
    input.ignore();
    input >> std::setw(3) >> number.areaCode;
    input.ignore(2);
    input >> std::setw(3) >> number.exchange;
    input.ignore();
    input >> std::setw(4) >> number.line;

    return input;
}