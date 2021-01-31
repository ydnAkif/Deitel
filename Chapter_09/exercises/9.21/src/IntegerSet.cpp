#include <iostream>
#include "IntegerSet.hpp"

IntegerSet::IntegerSet() : bitField(std::vector<bool>(SET_SIZE, false))
{
}

IntegerSet::IntegerSet(int *intArray, int intArraySize) : bitField(std::vector<bool>(SET_SIZE, false))
{
    for (size_t i = 0; i < intArraySize; ++i)
    {
        if (checkInput(intArray[i]))
        {
            insertElement(intArray[i]);
        }
    }
}

IntegerSet::~IntegerSet() {}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &b) const
{
    IntegerSet U;

    for (size_t i = 0; i < SET_SIZE; ++i)
    {
        if (this->bitField.at(i) || b.bitField.at(i))
        {
            U.bitField.at(i) = true;
        }
        else
        {
            U.bitField.at(i) = false;
        }
    }

    return U;
}

IntegerSet IntegerSet::interSectionOfSets(const IntegerSet &b) const
{
    IntegerSet S;

    for (size_t i = 0; i < SET_SIZE; ++i)
    {
        if (this->bitField.at(i) && b.bitField.at(i))
        {
            S.bitField.at(i) = true;
        }
        else
        {
            S.bitField.at(i) = false;
        }
    }

    return S;
}

void IntegerSet::insertElement(int k)
{
    if (checkInput(k))
    {
        this->bitField.at(k) = true;
    }
}

void IntegerSet::deleteElements(int m)
{
    if (checkInput(m))
    {
        this->bitField.at(m) = false;
    }
}

void IntegerSet::printSet() const
{
    bool empty = true;

    for (size_t i = 0; i < SET_SIZE; ++i)
    {
        if (this->bitField.at(i))
        {
            std::cout << i << " ";
            empty = false;
        }
    }

    std::cout << std::endl;
    if (empty)
    {
        std::cout << "---" << std::endl;
    }
}

bool IntegerSet::isEqualTo(const IntegerSet &b) const
{
    for (size_t i = 0; i < SET_SIZE; ++i)
    {
        if (this->bitField.at(i) != b.bitField.at(i))
        {
            return false;
        }
    }

    return true;
}

bool IntegerSet::checkInput(int k)
{
    if (k < 0 || k > SET_SIZE - 1)
    {
        throw("Invalid input, valid range: [0, " + std::to_string(SET_SIZE - 1) + "]");
        return false;
    }

    return true;
}