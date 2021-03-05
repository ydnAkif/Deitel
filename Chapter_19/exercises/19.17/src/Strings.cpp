#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Strings.hpp"

Strings::Strings(const char *ptr)
{
    length = strlen(ptr);
    sPtr = new char[length + 1];
    assert(sPtr != nullptr);
    strcpy(sPtr, ptr);
}

Strings::Strings(const Strings &copy)
{
    length = copy.length;
    sPtr = new char[length + 1];
    assert(sPtr != nullptr);
    strcpy(sPtr, copy.sPtr);
}

Strings::~Strings()
{
    delete[] sPtr;
}

const Strings &Strings::operator=(const Strings &right)
{
    if (&right != this)
    {
        delete[] sPtr;
        length = right.length;
        sPtr = new char[length + 1];
        assert(sPtr != nullptr);
        strcpy(sPtr, right.sPtr);
    }
    else
        std::cout << "Attempted assignment of a String to itself\n";

    return *this;
}

Strings &Strings::operator+=(const Strings &right)
{
    char *tempPtr = sPtr;
    length = right.length;
    sPtr = new char[length + 1];
    assert(sPtr != nullptr);
    strcpy(sPtr, tempPtr);
    strcat(sPtr, right.sPtr);
    delete[] tempPtr;
    return *this;
}

bool Strings::operator!() const { return length == 0; }

bool Strings::operator==(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) == 0;
}

bool Strings::operator!=(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) != 0;
}

bool Strings::operator<(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) < 0;
}

bool Strings::operator>(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) > 0;
}

bool Strings::operator<=(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) <= 0;
}

bool Strings::operator>=(const Strings &right) const
{
    return strcmp(sPtr, right.sPtr) >= 0;
}

char &Strings::operator[](int subscript)
{
    assert(subscript >= 0 && subscript < length);

    return sPtr[subscript];
}

Strings &Strings::operator()(int index, int subLength)
{
    assert(index >= 0 && index < length && subLength >= 0);
    Strings *subPtr = new Strings;
    assert(subPtr != nullptr);

    if ((subLength == 0) || (index + subLength > length))
        subPtr->length = length - index + 1;
    else
        subPtr->length = subLength + 1;

    delete subPtr->sPtr;
    subPtr->sPtr = new char[subPtr->length];
    assert(subPtr->sPtr != 0);

    strncpy(subPtr->sPtr, &sPtr[index], subPtr->length);
    subPtr->sPtr[subPtr->length] = '\0';

    return *subPtr;
}

int Strings::getLength() const
{
    return length;
}

std::ostream &operator<<(std::ostream &output, const Strings &s)
{
    output << s.sPtr;
    return output;
}

std::istream &operator>>(std::istream & input, Strings &s)
{
    char temp[100];

    input >> std::setw(100) >> temp;
    s = temp;

    return input;
}