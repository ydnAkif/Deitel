#ifndef DATE_HPP
#define DATE_HPP

class Date
{
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    unsigned int chechDay(int) const;

public:
    static const unsigned int monthsPerYear = 12;
    explicit Date(int = 1, int = 1, int = 1900);
    void print() const;
    ~Date();
};

#endif