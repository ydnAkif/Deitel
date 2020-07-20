#include <iostream>

class Date
{
private:
    int days = 1;
    int months = 1;
    int years = 1990;

public:
    Date(int, int, int);

    //Setters
    void setDays(int);
    void setMonths(int);
    void setYears(int);

    //Getters
    int getDays() const;
    int getMonths() const;
    int getYears() const;

    void displayDate() const;
};
