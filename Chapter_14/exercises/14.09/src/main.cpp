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
#include <string>

using std::string;

void printOutput(ofstream &, int, const string &, const string &, double);

int main(int argc, char const *argv[])
{
    int masterAccount, transactionAccount;
    double masterBalance, transactionBalance;
    string masterFirtsName, masterLastName;

    ifstream inOldMaster("../oldmaster.dat", ios::in);
    ifstream inTransaction("../transaction.dat", ios::in);

    ofstream outNewMaster("../newmaster.dat", ios::out);

    if (!inOldMaster)
    {
        cerr << "Unable to open oldmaster.dat.\n";
        exit(EXIT_FAILURE);
    }

    if (!inTransaction)
    {
        cerr << "Unable to open transaction.dat.\n";
        exit(EXIT_FAILURE);
    }

    if (!outNewMaster)
    {
        cerr << "Unable to open newmaster.dat.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Proccessing...\n";
    inTransaction >> transactionAccount >> transactionBalance;

    while (!inTransaction.eof())
    {
        inOldMaster >> masterAccount >> masterFirtsName >> masterLastName >> masterBalance;

        while (masterAccount < transactionAccount && !inOldMaster.eof())
        {
            printOutput(outNewMaster, masterAccount, masterFirtsName, masterLastName, masterBalance);
            inOldMaster >> masterAccount >> masterFirtsName >> masterLastName >> masterBalance;
        }

        if (masterAccount > transactionAccount)
        {
            cout << "Unmatched transaction record for account " << transactionAccount << '\n';
            inTransaction >> transactionAccount >> transactionBalance;
        }

        else if (masterAccount < transactionAccount)
        {
            cout << "Unmatched transaction record for account " << transactionAccount << '\n';
            inTransaction >> transactionAccount >> transactionBalance;
        }

        while (masterAccount == transactionAccount && !inTransaction.eof())
        {
            masterBalance += transactionBalance;
            inTransaction >> transactionAccount >> transactionBalance;
        }

        printOutput(outNewMaster, masterAccount, masterFirtsName, masterLastName, masterBalance);
    }

    inTransaction.close();
    outNewMaster.close();
    inOldMaster.close();

    return 0;
}

void printOutput(ofstream &output, int mAccount, const string &mFirst, const string &mLast, double mBalance)
{
    cout.setf(ios::fixed | ios::showpoint);
    output.setf(ios::fixed | ios::showpoint);

    output << mAccount << ' ' << mFirst << ' ' << mLast << ' '
           << setprecision(2) << mBalance << '\n';

    cout << mAccount << ' ' << mFirst << ' ' << mLast << ' '
         << setprecision(2) << mBalance << '\n';
    cout.unsetf(ios::fixed | ios::showpoint);
}