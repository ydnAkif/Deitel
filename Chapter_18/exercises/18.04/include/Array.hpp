#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <cassert>

template <class elementType, int numberOfElements>
class Array
{
private:
    elementType ptr[numberOfElements];
    int size;
    static int arrayCount;

public:
    Array();
    ~Array();
    int getSize() const;
    bool operator==(const Array &) const;
    bool operator!=(const Array &) const;
    elementType &operator[](int);
    static int getArrayCount();

    void inputArray();
    void outputArray() const;
};

template <class elementType, int numberOfElements>
int Array<elementType, numberOfElements>::arrayCount = 0;

template <class elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array()
{
    ++arrayCount;
    size = numberOfElements;

    for (int i = 0; i < size; ++i)
        ptr[i] = 0;
}

template <class elementType, int numberOfElements>
Array<elementType, numberOfElements>::~Array()
{
    --arrayCount;
}

template <class elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getSize() const
{
    return size;
}

template <class elementType, int numberOfElements>
bool Array<elementType, numberOfElements>::operator==(const Array &right) const
{
    if (size != right.size)
        return false;

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;

    return true;
}

template <class elementType, int numberOfElements>
bool Array<elementType, numberOfElements>::operator!=(const Array &right) const
{
    if (size != right.size)
        return true;

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return true;

    return false;
}

template <class elementType, int numberOfElements>
elementType &Array<elementType, numberOfElements>::operator[](int subscript)
{
    assert(0 <= subscript && subscript < size);

    return ptr[subscript];
}

template <class elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getArrayCount() { return arrayCount; }

template <class elementType, int numberOfElements>
void Array<elementType, numberOfElements>::inputArray()
{
    for (size_t i = 0; i < size; ++i)
        std::cin >> ptr[i];
}

template <class elementType, int numberOfElements>
void Array<elementType, numberOfElements>::outputArray() const
{
    size_t i;
    for (i = 0; i < size; ++i)
    {
        std::cout << ptr[i] << ' ';

        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }

    if (i % 10 != 0)
        std::cout << std::endl;
}

#endif