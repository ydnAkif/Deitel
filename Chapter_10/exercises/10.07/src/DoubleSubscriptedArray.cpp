#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "DoubleSubscriptedArray.hpp"

DoubleSubscriptedArray::DoubleSubscriptedArray(int c, int r)
{
    if (c > 0 && r >= 0)
    {
        cols = c;
        rows = r;
        size = ((rows > 0) ? (cols * rows) : cols);
    }
    else
    {
        throw std::invalid_argument("Array size must be greater than 0");
    }

    ptrData = new int[size];
    for (unsigned int i = 0; i < size; ++i)
    {
        ptrData[i] = 0;
    }
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &arrayToCopy)
    : cols(arrayToCopy.cols), rows(arrayToCopy.rows), size(arrayToCopy.size)
{
    ptrData = new int[size];
    for (unsigned int i = 0; i < size; ++i)
    {
        ptrData[i] = arrayToCopy.ptrData[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    delete[] ptrData;
    ptrData = nullptr;
}

int DoubleSubscriptedArray::getSize() const
{
    return size;
}

DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right)
{
    if (&right == this)
    {
        if (getSize() != right.getSize())
        {
            delete[] ptrData;
            ptrData = nullptr;
            cols = right.cols;
            rows = right.rows;
            size = right.getSize();

            ptrData = new int[size]();
        }

        for (unsigned int i = 0; i < size; ++i)
        {
            ptrData[i] = (right.ptrData)[i];
        }
    }

    return *this;
}

bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const
{
    if (getSize() != right.getSize())
    {
        return false;
    }

    for (size_t i = 0; i < getSize(); ++i)
    {
        if (ptrData[i] != right.ptrData[i])
        {
            return false;
        }
    }
    return true;
}

bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &right) const
{
    return !operator==(right);
}

int &DoubleSubscriptedArray::operator()(unsigned int subRow, unsigned int subCol)
{
    if (subRow >= rows || subCol >= cols)
    {
        throw std::out_of_range("Subscript out of range");
    }

    return ptrData[subCol + cols * subRow];
}

int &DoubleSubscriptedArray::operator()(unsigned int subRow, unsigned int subCol) const
{
    if (subRow >= rows || subCol >= cols)
    {
        throw std::out_of_range("Subscript out of range");
    }

    return ptrData[subCol + cols * subRow];
}

std::istream &operator>>(std::istream &input, DoubleSubscriptedArray &a)
{
    for (unsigned int i = 0; i < a.size; ++i)
    {
        input >> a.ptrData[i];
    }

    return input;
}
std::ostream &operator<<(std::ostream &output, const DoubleSubscriptedArray &a)
{
    for (unsigned int row = 0; row < a.rows; ++row)
    {
        for (unsigned int col = 0; col < a.cols; ++col)
        {
            output << std::setw(8) << a.ptrData[col + a.cols * row];
        }
        output << std::endl;
    }

    return output;
}
