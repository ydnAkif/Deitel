#include <iostream>
#include <iomanip>
#include <array>


const size_t salaryRange = 11;

using namespace std;

void wages(array<int, salaryRange> &);

void display(const array<int, salaryRange> &);

int main(int argc, char const *argv[])
{
    array<int, salaryRange> arrSalaries = {};

    cout << setiosflags(ios::fixed | ios::showpoint);

    wages(arrSalaries);
    display(arrSalaries);

    return 0;
}

void wages(array<int, salaryRange> &arrSalaries)
{
    double sales, i = 0.09;
    cout << "Enter employee gross sales (-1 to end): ";
    cin >> sales;

    while (sales != -1)
    {
        double salary = 200.0 + sales * i;
        cout << setprecision(2) << "Employee Commission is $" << salary << endl;
        int x = static_cast<int>(salary) / 100;
        ++arrSalaries[(x < 10 ? x : 10)];
        cout << endl
             << "Enter employee gross sales (-1 to end):";
        cin >> sales;
    }
}

void display(const array<int, salaryRange> &arrSalaries)
{
    cout << "Employees in the range:";

    for (unsigned int i = 2; i < 10; ++i)
        cout << "\n$" << i << "00-$" << i << "99 : " << arrSalaries[i];
    cout << "\nOver $1000: " << arrSalaries[10] << endl;
}