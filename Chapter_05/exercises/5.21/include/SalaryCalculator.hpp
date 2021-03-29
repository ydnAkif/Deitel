
class SalaryCalculator
{
private:
    const double COMMISSION_BASE{250.0f};
    const double COMMISSION_RATE{0.057f};
    const double HOURLY_OVERTIME{1.5f};
    const double PIECE_RATE{10.0f};

    double managerRate{0.0f};
    double hourlyRate{0.0f};
    double weeklySales{0.0f};
    double hoursWorked{0.0f};

    int employeeCode{0};
    int piecesProduced{0};

public:
    SalaryCalculator();

    //Setters

    void setManagerRate(double);
    void setHourlyRate(double);
    void setWeeklySales(double);
    void setHoursWorked(double);
    void setEmployeeCode(int);
    void setPiecesProduced(int);

    //Getters

    double getManagerRate() const;
    double getHourlyRate() const;
    double getWeeklySales() const;
    double getHoursWorked() const;
    int getEmployeeCode() const;
    int getPiecesProduced() const;

    void inputSalaries();
    double calculateSalary();
    void reset();
};
