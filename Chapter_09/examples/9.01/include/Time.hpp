// Figure 9.1 Time.h
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
    Time();
    ~Time();

    void setTime(int, int, int);
    void printUniversal() const;
    void printStandart() const;
};

#endif