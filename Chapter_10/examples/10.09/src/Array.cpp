#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Array.hpp"

Array::Array(int arraySize)
    : size(arraySize > 0 ? arraySize : throw std::invalid_argument("Array size must be greater than 0")), ptr(new int[size])
{
    for (size_t i = 0; i < size; ++i)
        ptr[i] = 0;
}

Array::Array(const Array &arrayToCopy) : size(arrayToCopy.size), ptr(new int[size])
{
    for (size_t i = 0; i < size; ++i)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array::~Array()
{
    delete[] ptr;
}

size_t Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }

        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i];
    }

    return *this;
}

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
        return false;
    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}

bool Array::operator!=(const Array &right) const
{
    return !(*this == right);
}

int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
        throw std::out_of_range("Subscript out of range");

    return ptr[subscript];
}

int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size)
        throw std::out_of_range("Subscript out of range");

    return ptr[subscript];
}

std::istream &operator>>(std::istream &input, Array &a)
{
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input;
}

std::ostream &operator<<(std::ostream &output, const Array &a)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        output << std::setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0)
            output << std::endl;
    }

    if (a.size % 4 != 0)
        output << std::endl;

    return output;
}