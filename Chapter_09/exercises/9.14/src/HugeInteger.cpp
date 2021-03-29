#include "HugeInteger.hpp"
#include <iostream>

HugeInteger::HugeInteger(const std::string &numberString) : digits(std::array<int, nDigits>()), sign('+')
{
    input(numberString);
}

HugeInteger::~HugeInteger() {}

HugeInteger::HugeInteger(const HugeInteger &b) : digits(b.digits), sign(b.sign)
{
    *this = b;
}

void HugeInteger::input(const std::string &numberString)
{
    size_t strLength = numberString.length();

    for (size_t i = strLength - 1, j = nDigits - 1; i != 0; --i, --j)
    {
        digits.at(j) = numberString.at(i) - '0';
    }
    if (numberString.at(0) == '+' || numberString.at(0) == '-')
    {
        sign = numberString.at(0);
    }
    else
    {
        digits.at(nDigits - strLength) = numberString.at(0) - '0';
        sign = '+';
    }
}

std::string HugeInteger::output() const
{
    for (size_t i = 0; digits[i] == 0 && i < nDigits - 1; ++i)
    {
        std::cout << ' ';
    }
    std::cout << sign;
    for (size_t i = 0; i < digits.size(); ++i)
    {
        std::cout << digits[i];
    }
    std::cout << std::endl;

    return std::string();
}

HugeInteger &HugeInteger::add(const HugeInteger &b)
{
    if (this->sign == b.sign)
    {
        this->absoluteAdd(b);
        return *this;
    }
    else
    {
        if (isAbsoluteNotLessThan(b))
        {
            for (int i = nDigits - 1; i >= 0; --i)
            {
                if (this->digits[i] >= b.digits[i])
                {
                    this->digits[i] -= b.digits[i];
                }
                else
                {
                    if (i >= 1)
                    {
                        this->digits[i - 1] -= 1;
                        this->digits[i] += 10;
                    }
                    this->digits[i] -= b.digits[i];
                }
            }

            return *this;
        }
        else
        {
            HugeInteger temp(b);
            for (int i = nDigits - 1; i >= 0; --i)
            {
                if (temp.digits[i] >= this->digits[i])
                {
                    temp.digits[i] -= this->digits[i];
                }
                else
                {
                    if (i >= 1)
                    {
                        temp.digits[i - 1] -= 1;
                        temp.digits[i] += 10;
                    }
                    temp.digits[i] -= this->digits[i];
                }
            }
            *this = temp;
            return *this;
        }
    }
    return *this;
}

HugeInteger &HugeInteger::subtract(const HugeInteger &b)
{
    HugeInteger temp(b);
    if (b.sign == '-')
    {
        temp.sign = '+';
    }
    else
    {
        temp.sign = '-';
    }

    return this->add(temp);
}

HugeInteger &HugeInteger::multiply(const HugeInteger &b)
{
    HugeInteger temp(b);
    temp.sign = '+';

    HugeInteger temp2(*this);
    temp2.sign = '+';

    while (temp.subtract(HugeInteger("1")).isGreaterThan(HugeInteger("1")))
    {
        this->absoluteAdd(temp2);
    }

    if (this->sign != b.sign)
    {
        this->sign = '-';
    }
    else
    {
        this->sign = '+';
    }

    return *this;
}

HugeInteger &HugeInteger::divide(const HugeInteger &b)
{
    if (b.isZero())
    {
        throw("Diveded by Zero");
    }
    char quotientSign = '+';
    if (this->sign != b.sign)
    {
        quotientSign = '-';
    }

    HugeInteger absoluteThis = *this;
    absoluteThis.sign = '+';
    HugeInteger absoluteB = b;
    absoluteB.sign = '+';

    HugeInteger quotient("0");

    if (absoluteThis.isEqualTo(absoluteB))
    {
        quotient = HugeInteger("1");
        quotient.sign = quotientSign;
        this->operator=(quotient);
        return *this;
    }
    else if (this->isAbsoluteNotLessThan(b))
    {
        while (absoluteThis.subtract(absoluteB).isGreaterThan(HugeInteger("0")))
        {
            quotient.add(HugeInteger("1"));
        }
        quotient.sign = quotientSign;
        this->operator=(quotient);
        return *this;
    }

    else
    {
        this->operator=(HugeInteger("0"));
        return *this;
    }

    return *this;
}

HugeInteger &HugeInteger::modulus(const HugeInteger &b)
{
    if (b.isZero())
    {
        throw("Modulus zero is undefined");
    }

    HugeInteger result = this->absolute();
    HugeInteger numerator = this->absolute();
    HugeInteger denominator = b.absolute();
    numerator.divide(denominator);

    if (numerator.multiply(denominator).isEqualTo(this->absolute()))
    {
        this->operator=(HugeInteger("0"));
        return *this;
    }

    else
    {
        result.subtract(numerator);
        if (this->sign == b.sign)
        {
            result.sign = '+';
        }
        else
        {
            result.sign = '-';
        }

        this->operator=(result);
    }

    return *this;
}

HugeInteger &HugeInteger::operator=(const HugeInteger &b)
{
    this->sign = b.sign;

    for (size_t i = 0; i < nDigits; ++i)
    {
        this->digits[i] = b.digits[i];
    }
    return *this;
}

HugeInteger &HugeInteger::absoluteAdd(const HugeInteger &b)
{
    for (int i = nDigits - 1; i >= 0; --i)
    {
        this->digits[i] += b.digits[i];
        if (this->digits[i] >= 10)
        {
            if (i >= 1)
            {
                this->digits[i - 1] += 1;
            }
            this->digits[i] -= 10;
        }
    }

    return *this;
}

bool HugeInteger::isAbsoluteNotLessThan(const HugeInteger &b) const
{
    for (size_t i = 0; i < nDigits; ++i)
    {
        if (this->digits[i] > b.digits[i])
        {
            return true;
        }
        else if (this->digits[i] < b.digits[i])
        {
            return false;
        }
    }
    return true;
}

bool HugeInteger::isEqualTo(const HugeInteger &b) const
{
    if (this->sign != b.sign)
    {
        return false;
    }

    for (size_t i = 0; i < nDigits; ++i)
    {
        if (this->digits[i] != b.digits[i])
        {
            return false;
        }
    }
    return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &b) const
{
    return !isEqualTo(b);
}

bool HugeInteger::isGreaterThan(const HugeInteger &b) const
{
    if (this->sign == b.sign)
    {
        if (isAbsoluteNotLessThan(b))
        {
            if (this->sign == '+')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (this->sign == '-')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if (this->sign == '+')
    {
        return true;
    }
    return false;
}

bool HugeInteger::isLessThan(const HugeInteger &b) const
{
    return (!isGreaterThan(b) && (!isEqualTo(b)));
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger &b) const
{
    return (!isLessThan(b));
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger &b) const
{
    return (!isGreaterThan(b));
}

bool HugeInteger::isZero() const
{
    for (size_t i = 0; i < nDigits; ++i)
    {
        if (this->digits[i] != 0)
        {
            return false;
        }
    }

    return true;
}

const HugeInteger HugeInteger::absolute() const
{
    HugeInteger abs(*this);
    abs.sign = '+';

    return abs;
}