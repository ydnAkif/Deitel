#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    explicit Time(int = 0, int = 0, int = 0);
    ~Time();

    // Setters
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Getters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printStandard() const;
    void printUniversal() const;
    void tick();
};

#endif