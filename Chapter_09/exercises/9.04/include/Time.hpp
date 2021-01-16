#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    ~Time();

    // Setters
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Getters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printStandard() const;
    void printUniversal() const;
};

#endif