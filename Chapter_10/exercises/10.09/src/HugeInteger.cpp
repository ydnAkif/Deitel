#include <cctype>
#include "HugeInteger.hpp"

HugeInteger::HugeInteger(long value)
{
    for (short &element : integer)
        element = 0;

    for (size_t j = digits - 1; value != 0 && j >= 0; --j)
    {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInteger::HugeInteger(const std::string &number)
{
    for (short &element : integer)
        element = 0;

    size_t lenght = number.size();

    for (size_t j = digits - lenght, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
}

HugeInteger::~HugeInteger()
{
}

HugeInteger HugeInteger::operator+(const HugeInteger &right) const
{
    HugeInteger temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; --i)
    {
        temp.integer[i] = integer[i] + right.integer[i] + carry;

        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return temp;
}

HugeInteger HugeInteger::operator+(int right) const
{
    return (*this + HugeInteger(right));
}

HugeInteger HugeInteger::operator+(const std::string &right) const
{
    return (*this + HugeInteger(right));
}

HugeInteger HugeInteger::operator*(const HugeInteger &right) const
{
    HugeInteger temp(0), product(0);

    for (; temp < right; temp = temp + HugeInteger(1))
    {
        product = product + *this;
    }

    return product;
}

HugeInteger HugeInteger::operator*(int right) const
{
    return (*this * HugeInteger(right));
}

HugeInteger HugeInteger::operator*(const std::string &right) const
{
    return (*this * HugeInteger(right));
}

HugeInteger HugeInteger::operator/(const HugeInteger &right) const
{
    HugeInteger result(0);

    if (right == result)
    {
        throw "divided by zero\n";
        return result;
    }
    if (*this < right)
    {
        return result;
    }
    while ((result * right + right) <= *this)
    {
        result = result + HugeInteger(1);
    }

    return result;
}

HugeInteger HugeInteger::operator/(int right) const
{
    return (*this / HugeInteger(right));
}

HugeInteger HugeInteger::operator/(const std::string &right) const
{
    return (*this / HugeInteger(right));
}

bool HugeInteger::operator==(const HugeInteger &right) const
{
    return (integer == right.integer);
}

bool HugeInteger::operator!=(const HugeInteger &right) const
{
    return (!operator==(right));
}

bool HugeInteger::operator>(const HugeInteger &right) const
{
    return (integer > right.integer);
}

bool HugeInteger::operator>=(const HugeInteger &right) const
{
    return ((integer > right.integer) || (integer == right.integer));
}

bool HugeInteger::operator<(const HugeInteger &right) const
{
    return (integer < right.integer);
}

bool HugeInteger::operator<=(const HugeInteger &right) const
{
    return (integer < right.integer) || (integer == right.integer);
}

std::ostream &operator<<(std::ostream &output, const HugeInteger &num)
{
    size_t i;

    for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i)
    {
        ;
    }

    if (i == HugeInteger::digits)
    {
        output << 0;
    }
    else
    {
        for (; i < HugeInteger::digits; ++i)
        {
            output << num.integer[i];
        }
    }

    return output;
}