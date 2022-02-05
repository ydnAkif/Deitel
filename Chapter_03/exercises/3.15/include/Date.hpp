
#if !defined(DATE_HPP)
#define DATE_HPP

class Date
{
private:
    short day;
    short month;
    short year;

public:
    Date();
    Date(const short, const short, const short);

    // Setters Declarations
    void setDay(const short);
    void setMonth(const short);
    void setYear(const short);

    // Getters Declarations
    short getDay() const;
    short getMonth() const;
    short getYear() const;

    void displayDate() const;
};

#endif // DATE_HPP
