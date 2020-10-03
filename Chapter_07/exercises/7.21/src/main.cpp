#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

const size_t PEOPLE = 5;
const size_t PRODUCTS = 6;

int main()
{
    array<array<double, PEOPLE>, PRODUCTS> sales = {};
    double value, totalSales;
    array<double, PRODUCTS> productSales;

    int salesPerson, product;

    cout << "Enter the salesperson (1 - 4), product number (1 - 5), "
         << "and total sales." << endl
         << "Enter -1 for the salesperson to end input.\n";

    cin >> salesPerson;

    while (salesPerson != -1)
    {
        cin >> product >> value;
        sales[salesPerson][product] += value;
        cin >> salesPerson;
    }
    cout << "\nThe total sales for each salesperson are displayed"
         << " at the end of each row,\n"
         << "and the total sales for"
         << " each product are displayed at the bottom of each\n"
         << "column.\n " << setw(12) << 1 << setw(12) << 2
         << setw(12) << 3 << setw(12) << 4 << setw(12) << 5 << setw(13)
         << "Total\n"
         << setiosflags(ios::fixed | ios::showpoint);

    for (size_t i = 1; i < PEOPLE; ++i)

    {
        totalSales = 0.0;
        cout << i;

        for (size_t j = 1; j < PRODUCTS; ++j)
        {
            totalSales += sales[i][j];
            cout << setw(12) << setprecision(2) << sales[i][j];
            productSales[j] += sales[i][j];
        }

        cout << setw(12) << setprecision(2) << totalSales << '\n';
    }

    cout << "\nTotal" << setw(8) << setprecision(2) << productSales[1];

    for (size_t k = 2; k < PRODUCTS; ++k)
        cout << setw(12) << setprecision(2) << productSales[k];
    cout << endl;

    return 0;
}