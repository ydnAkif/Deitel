// Figure 9.1 Time.h
// Time class definition
// Member functions are defined in Time.cpp
#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
    unsigned int secondsSinceMidNight;

public:
    explicit Time(int = 0, int = 0, int = 0);

    // Set functions

    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Get functions

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    // Print functions

    void printUniversal() const;
    void printStandart() const;
};

#endif