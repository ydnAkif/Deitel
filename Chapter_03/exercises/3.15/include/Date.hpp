
#if !defined(DATE_HPP)
#define DATE_HPP

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(const int, const int, const int);

    // Setters Declarations
    void setDay(const int);
    void setMonth(const int);
    void setYear(const int);

    // Getters Declarations
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void displayDate() const;
};

#endif // DATE_HPP
