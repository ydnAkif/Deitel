#include <iostream>

using std::cerr;
using std::cout;
using std::ios;

#include <iomanip>

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
    string masterFirstName, masterLastName;

    ifstream inOldMaster("../oldmaster.dat", ios::in), inTransaction("../transaction.dat", ios::in);
    ofstream outNewMaster("../newmaster.dat", ios::out | ios::binary);

    if (!inOldMaster)
    {
        cerr << "Unable to open oldmaster.dat\n";
        exit(EXIT_FAILURE);
    }

    if (!inTransaction)
    {
        cerr << "Unable to open transaction.dat\n";
        exit(EXIT_FAILURE);
    }

    if (!outNewMaster)
    {
        cerr << "Unable to open newmaster.dat\n";
        exit(EXIT_FAILURE);
    }

    cout << "Proccessing...\n";
    inTransaction >> transactionAccount >> transactionBalance;
    while (!inTransaction.eof())
    {
        inOldMaster >> masterAccount >> masterFirstName >> masterLastName >> masterBalance;

        while (masterAccount < transactionAccount && !inOldMaster.eof())
        {
            printOutput(outNewMaster, masterAccount, masterFirstName, masterLastName, masterBalance);
            inOldMaster >> masterAccount >> masterFirstName >> masterLastName >> masterBalance;
        }

        if (masterAccount > transactionAccount)
        {
            cout << "Unmatched transaction record for account "
                 << transactionAccount << '\n';
            inTransaction >> transactionAccount >> transactionBalance;
        }

        if (masterAccount == transactionAccount)
        {
            masterBalance += transactionBalance;
            printOutput(outNewMaster, masterAccount, masterFirstName, masterLastName, masterBalance);
        }

        inTransaction >> transactionAccount >> transactionBalance;
    }

    inTransaction.close();
    outNewMaster.close();
    inOldMaster.close();

    return 0;
}

void printOutput(ofstream &output, int mAccount, const string &mfName, const string &mlName, double mBalance)
{
    cout.setf(ios::fixed | ios::showpoint);
    output.setf(ios::fixed | ios::showpoint);

    output << mAccount << ' ' << mfName << ' ' << mlName << ' '
           << setprecision(2) << mBalance << '\n';
    cout << mAccount << ' ' << mfName << ' ' << mlName << ' '
         << setprecision(2) << mBalance << '\n';
}