#ifndef DATE_HPP
#define DATE_HPP

#include <array>
#include <ctime>

class Date
{
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const unsigned int monthsPerYear = 12;
    static const std::array<int, monthsPerYear + 1> daysPerMonth;
    static const std::array<std::string, Date::monthsPerYear + 1> monthsNames;
    int getMonthFromString(std::string) const;
    unsigned int chechDay(int) const;

public:
    explicit Date(int = 1, int = 1, int = 1900);
    Date(std::string);
    Date(time_t);

    void print() const;
    void printDDD_YYYY() const;
    void printMM_DD_YY() const;
    void printEn_US() const;
    ~Date();
};

#endif