#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <iostream>

class Strings
{
    friend std::ostream &operator<<(std::ostream &, const Strings &);
    friend std::istream &operator>>(std::istream &, Strings &);

private:
    char *sPtr;
    int length;

public:
    Strings(const char * = "");
    Strings(const Strings &);
    ~Strings();
    const Strings &operator=(const Strings &);
    Strings &operator+=(const Strings &);
    bool operator!() const;
    bool operator==(const Strings &) const;
    bool operator!=(const Strings &) const;
    bool operator<(const Strings &) const;
    bool operator>(const Strings &) const;
    bool operator>=(const Strings &) const;
    bool operator<=(const Strings &) const;
    char &operator[](int);
    Strings &operator()(int, int);
    int getLength() const;
};

#endif