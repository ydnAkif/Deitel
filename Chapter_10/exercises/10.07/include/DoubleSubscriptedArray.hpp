#ifndef DOUBLE_SUBSCRIPTED_ARRAY_HPP
#define DOUBLE_SUBSCRIPTED_ARRAY_HPP

#include <iostream>

class DoubleSubscriptedArray
{
    friend std::istream &operator>>(std::istream &, DoubleSubscriptedArray &);
    friend std::ostream &operator<<(std::ostream &, const DoubleSubscriptedArray &);

private:
    int rows;
    int cols;
    int size;
    int *ptrData;

public:
    explicit DoubleSubscriptedArray(int = 10, int = 0);
    DoubleSubscriptedArray(const DoubleSubscriptedArray &);
    ~DoubleSubscriptedArray();

    int getSize() const;

    DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);

    bool operator==(const DoubleSubscriptedArray &) const;
    bool operator!=(const DoubleSubscriptedArray &) const;

    int &operator()(unsigned int, unsigned int);
    int &operator()(unsigned int, unsigned int) const;
};

#endif