#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array
{

    friend std::ostream &operator<<(std::ostream &, const Array &);
    friend std::istream &operator>>(std::istream &, Array &);

private:
    size_t size;
    int *ptr;

public:
    explicit Array(int = 10);
    Array(const Array &);
    ~Array();
    size_t getSize() const;

    const Array &operator=(const Array &);
    bool operator==(const Array &) const;
    bool operator!=(const Array &) const;

    int &operator[](int);
    int operator[](int) const;
};

#endif