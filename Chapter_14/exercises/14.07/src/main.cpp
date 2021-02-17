#include <iostream>

using std::cerr;
using std::cout;
using std::ios;

#include <iomanip>

using std::setiosflags;
using std::setprecision;

#include <fstream>

using std::ifstream;
using std::ofstream;

#include <cstdlib>
#include <array>

using std::array;

#include <ctime>
#include <string>

using std::string;

int main(int argc, char const *argv[])
{
    array<string, 10> firstNames = {"Walter", "Alice", "Alan", "Mary", "Steve",
                                    "Gina", "Tom", "Cindy", "Ilana", "Pam"};
    array<string, 15> lastNames = {"Red", "Blue", "Yellow", "Orange", "Purple",
                                   "Green", "Violet", "White", "Black", "Brown"};
    ofstream outOldMaster("../oldmaster.dat", ios::out);
    ofstream outTransaction("../transaction.dat", ios::out);

    int z;

    srand(time(0));

    if (!outOldMaster)
    {
        cerr << "Unable to open oldmaster.dat.\n";
        exit(EXIT_SUCCESS);
    }

    if (!outTransaction)
    {
        cerr << "Unable to open transaction.dat.\n";
        exit(EXIT_SUCCESS);
    }

    cout << setiosflags(ios::fixed | ios::showpoint)
         << "Contents of \"oldmaster.dat\":\n";

    outOldMaster.setf(ios::fixed | ios::showpoint);

    for (z = 1; z < 11; ++z)
    {
        int value = rand() % 10, value2 = rand() % 50;
        outOldMaster << z * 100 << ' ' << firstNames[z - 1] << ' '
                     << lastNames[value] << ' ' << setprecision(2)
                     << (value * 100) / (value2 / 3 + 4.42) << '\n';
        cout << z * 100 << ' ' << firstNames[z - 1] << ' '
             << lastNames[value] << ' ' << setprecision(2)
             << (value * 100) / (value2 / 3 + 4.42) << '\n';
    }

    cout << "\nContents of \"transaction.dat\":\n";
    outTransaction.setf(ios::fixed | ios::showpoint);

    for (z = 1; z < 11; ++z)
    {
        int value = 25 - rand() % 50;

        outTransaction << z * 100 << ' ' << setprecision(2)
                       << (value * 100) / (2.667 * (1 + rand() % 10)) << '\n';

        cout << z * 100 << ' ' << setprecision(2)
             << (value * 100) / (2.667 * (1 + rand() % 10)) << '\n';
    }

    outTransaction.close();
    outOldMaster.close();

    ifstream inOldMaster("../oldmaster.dat", ios::in);
    ifstream inTransaction("../transaction.dat", ios::in);

    ofstream newOfMaster("../newmaster.dat", ios::out);

    if (!inOldMaster)
    {
        cerr << "Unable to open oldmaster.dat.\n";
        exit(EXIT_SUCCESS);
    }

    if (!inTransaction)
    {
        cerr << "Unable to open transaction.dat.\n";
        exit(EXIT_SUCCESS);
    }

    if (!newOfMaster)
    {
        cerr << "Unable to open newmaster.dat.\n";
        exit(EXIT_SUCCESS);
    }

    int transAccount, mAccount;
    double transBalance, mBalance;
    string mFirst, mLast;

    cout << "Proccessing...\n";

    while (inTransaction >> transAccount >> transBalance)
    {
        inOldMaster >> mAccount >> mFirst >> mLast >> mBalance;

        while (mAccount < transAccount && !inOldMaster.eof())
            inOldMaster >> mAccount >> mFirst >> mLast >> mBalance;

        if (mAccount > transAccount)
        {
            cout << "Unmatched transaction record: account " << transAccount << '\n';
            inTransaction >> transAccount >> transBalance;
        }

        if (mAccount == transAccount)
        {
            mBalance += transBalance;
            newOfMaster << mAccount << ' ' << mFirst << ' ' << mLast << ' ' << mBalance << '\n';
        }
        }

    newOfMaster.close();
    inTransaction.close();
    inOldMaster.close();

    return 0;
}
