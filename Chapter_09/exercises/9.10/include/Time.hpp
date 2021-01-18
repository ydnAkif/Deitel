
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
    enum error_status
    {
        eOk = 0,
        eInvalidHour = 1,
        eInvalidMinute = 2,
        eInvalidSecond = 3,
        eInvalidTime = 4
    };
    // Set functions

    error_status setTime(int, int, int);
    error_status setHour(int);
    error_status setMinute(int);
    error_status setSecond(int);

    // Get functions

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    // Print functions

    void printUniversal() const;
    void printStandart() const;
    void printSetError(error_status);
};

#endif