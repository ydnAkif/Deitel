#ifndef INTEGER_SET_HPP
#define INTEGER_SET_HPP
#include <vector>
#include <string>

const int SET_SIZE = 101;

class IntegerSet
{
private:
    std::vector<bool> bitField;
    bool checkInput(int);

public:
    explicit IntegerSet();
    IntegerSet(int *, int);
    ~IntegerSet();
    IntegerSet unionOfSets(const IntegerSet &) const;
    IntegerSet interSectionOfSets(const IntegerSet &) const;
    void insertElement(const int);
    void deleteElements(const int);

    void printSet() const;
    bool isEqualTo(const IntegerSet &) const;
};

#endif