#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array
{
    friend std::ostream &operator<<(std::ostream &, const Array &);
    friend std::istream &operator>>(std::istream &, Array &);

public:
    Array(int = 10);        // default constructor
    Array(const Array &);   // copy constructor
    ~Array();               // destructor
    size_t getSize() const; // return size

    const Array &operator=(const Array &); // assignment operator
    bool operator==(const Array &) const;  // equality operator

    // inequality operator; returns opposite of == operator
    bool operator!=(const Array &right) const
    {
        return !(*this == right); // invokes Array::operator==
    }

    // subscript operator for non-const objects returns modifiable lvalue
    int &operator[](int);

    // subscript operator for const objects returns rvalue
    int operator[](int) const;

private:
    size_t size; // pointer-based array size
    int *ptr;    // pointer to first element of pointer-based array
};

#endif