#include <iostream>
#include <vector>
#include <iomanip>

const size_t salaryRange = 11;

using namespace std;

void wages(vector<int> &);

void display(const vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> vecSalaries(salaryRange);

    cout << setiosflags(ios::fixed | ios::showpoint);

    wages(vecSalaries);
    display(vecSalaries);

    return 0;
}

void wages(vector<int> &vecSalaries)
{
    double sales, i = 0.09;
    cout << "Enter employee gross sales (-1 to end): ";
    cin >> sales;

    while (sales != -1)
    {
        double salary = 200.0 + sales * i;
        cout << setprecision(2) << "Employee Commission is $" << salary << endl;
        int x = static_cast<int>(salary) / 100;
        ++vecSalaries[(x < 10 ? x : 10)];
        cout << endl
             << "Enter employee gross sales (-1 to end):";
        cin >> sales;
    }
}

void display(const vector<int> &vecSalaries)
{
    cout << "Employees in the range:";

    for (unsigned int i = 2; i < 10; ++i)
        cout << "\n$" << i << "00-$" << i << "99 : " << vecSalaries[i];
    cout << "\nOver $1000: " << vecSalaries[10] << endl;
}