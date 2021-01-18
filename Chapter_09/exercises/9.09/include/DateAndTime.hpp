#ifndef DATE_AND_TIME__HPP
#define DATE_AND_TIME__HPP

class DateAndTime
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

public:
    explicit DateAndTime(int = 1, int = 1, int = 2000, int = 0, int = 0, int = 0);

    // Setter functions
    void setDate(int, int, int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Getter functions
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Auxilary functions
    bool leapYear() const;
    void nextDay();
    int monthDays();
    void tick();

    // Display functions
    void printStandard() const;
    void printUniversal() const;
};

#endif