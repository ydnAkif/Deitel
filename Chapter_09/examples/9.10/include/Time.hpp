// Figure 9.10 Time.h
// Time class definition
// Member functions are defined in Time.cpp
#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
    unsigned int hour;   // 00-23
    unsigned int minute; // 00-59
    unsigned int second; // 00-59

public:
    explicit Time(int = 0, int = 0, int = 0);

    // Set functions

    void setTime(int, int, int);

    // Get functions

    unsigned int getHour() const;
    unsigned int &badSetHour(int);

    // Print functions

    void printUniversal() const;
    void printStandart() const;
};

#endif