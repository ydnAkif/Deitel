#ifndef DATE_HPP
#define DATE_HPP

class Date
{
private:
    int month;
    int day;
    int year;

public:
    explicit Date(int = 1, int = 1, int = 2000);
    ~Date();

    void print() const;

    void setDate(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool leapYear();
    int monthDays();
    void nextDay();
};

#endif