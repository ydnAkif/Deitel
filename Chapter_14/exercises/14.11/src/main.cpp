#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>

using std::resetiosflags;
using std::setiosflags;
using std::setprecision;
using std::setw;

#include <fstream>

using std::fstream;
using std::ifstream;
using std::ofstream;

#include <string>

using std::string;

#include <cctype>
#include <cstdlib>

void initializeFile(fstream &);
void inputData(fstream &);
void listTools(fstream &);
void updateRecord(fstream &);
void insertRecord(fstream &);
void deleteeRecord(fstream &);

int instructions();

const int LENGTH = 30;

struct Data
{
    int partNumber;
    char toolName[LENGTH];
    int inStock;
    double unitPrice;
};

int main(int argc, char const *argv[])
{
    int choice;
    char response;
    fstream file("../hardware.dat", ios::in | ios::out);

    void (*f[])(fstream &) = {listTools, updateRecord, insertRecord, deleteeRecord};

    if (!file)
    {
        cerr << "Unable to open hardware.dat.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Should the file be initialized ( Y or N): ";
    cin >> response;

    while (toupper(response) != 'Y' && toupper(response) != 'N')
    {
        cout << "Invalid response. Enter Y or N: ";
        cin >> response;
    }

    if (toupper(response) == 'Y')
    {
        initializeFile(file);
        inputData(file);
    }

    while ((choice = instructions()) != 5)
    {
        (*f[choice - 1])(file);
        file.clear();
    }

    file.close();

    return 0;
}

void initializeFile(fstream &fRef)
{
    Data blankItem = {-1, "", 0, 0.0};
    for (int i = 0; i < 100; ++i)
        fRef.write(reinterpret_cast<char *>(&blankItem), sizeof(Data));
}

void inputData(fstream &fRef)
{
    Data temp;

    cout << "Enter the part number (0-99, -1 to end input): ";
    cin >> temp.partNumber;

    while (temp.partNumber != -1)
    {
        cout << "Enter the tool name: ";
        cin.ignore();
        cin.get(temp.toolName, LENGTH);
        cout << "Enter quantity and price: ";
        cin >> temp.inStock >> temp.unitPrice;

        fRef.seekp((temp.partNumber) * sizeof(Data));
        fRef.write(reinterpret_cast<char *>(&temp), sizeof(Data));

        cout << "Enter the part number (0-99, -1 to end input): ";
        cin >> temp.partNumber;
    }
}

void listTools(fstream &fRef)
{
    Data temp;

    cout << setw(7) << "Record#"
         << "   " << setiosflags(ios::left)
         << setw(30) << "Tool name" << resetiosflags(ios::left)
         << setw(13) << "Quantity" << setw(10) << "Cost\n";

    for (int count = 0; count < 100 && !fRef.eof(); ++count)
    {
        fRef.seekg(count * sizeof(Data));
        fRef.read(reinterpret_cast<char *>(&temp), sizeof(Data));

        if (temp.partNumber >= 0 && temp.partNumber < 100)
        {
            cout.setf(ios::fixed | ios::showpoint);
            cout << setw(7) << temp.partNumber << "    "
                 << setiosflags(ios::left) << setw(30) << temp.toolName
                 << resetiosflags(ios::left) << setw(13) << temp.inStock
                 << setprecision(2) << setw(10) << temp.unitPrice << '\n';
        }
    }
}

void updateRecord(fstream &fRef)
{
    Data temp;
    int part;

    cout << "Enter the part number for update: ";
    cin >> part;

    fRef.seekg(part * sizeof(Data));
    fRef.read(reinterpret_cast<char *>(&temp), sizeof(Data));

    if (temp.partNumber != -1)
    {
        cout << setw(7) << "Record#"
             << "   " << setiosflags(ios::left)
             << setw(30) << "Tool name" << resetiosflags(ios::left)
             << setw(13) << "Quantity" << setw(10) << "Cost\n";

        cout.setf(ios::fixed | ios::showpoint);

        cout << setw(7) << temp.partNumber << "    "
             << setiosflags(ios::left) << setw(30) << temp.toolName
             << resetiosflags(ios::left) << setw(13) << temp.inStock
             << setprecision(2) << setw(10) << temp.unitPrice << '\n'
             << "Enter the tool name: ";
        cin.ignore();
        cin.get(temp.toolName, LENGTH);
        cout << "Enter quantity and price: ";
        cin >> temp.inStock >> temp.unitPrice;

        fRef.seekp((temp.partNumber) * sizeof(Data));
        fRef.write(reinterpret_cast<char *>(&temp), sizeof(Data));
    }
    else
        cerr << "Can not update. The record is empty.\n";
}

void insertRecord(fstream &fRef)
{
    Data temp;
    int part;

    cout << "Enter the part number for insertion: ";
    cin >> part;

    fRef.seekg(part * sizeof(Data));
    fRef.read(reinterpret_cast<char *>(&temp), sizeof(Data));

    if (temp.partNumber == -1)
    {
        temp.partNumber = part;
        cout << "Enter the tool name: ";
        cin.ignore();
        cin.get(temp.toolName, LENGTH);

        cout << "Enter quantity and price: ";
        cin >> temp.inStock >> temp.unitPrice;

        fRef.seekp((temp.partNumber) * sizeof(Data));
        fRef.write(reinterpret_cast<char *>(&temp), sizeof(Data));
    }
    else
        cerr << "Can not insert. The record contains information.\n";
}

void deleteeRecord(fstream &fRef)
{
    Data blankItem = {-1, "", 0, 0.0}, temp;
    int part;

    cout << "Enter the part number for deletion: ";
    cin >> part;

    fRef.seekg(part * sizeof(Data));
    fRef.read(reinterpret_cast<char *>(&temp), sizeof(Data));

    if (temp.partNumber != -1)
    {
        fRef.seekp(part * sizeof(Data));
        fRef.write(reinterpret_cast<char *>(&blankItem), sizeof(Data));

        cout << "Record deleted.\n";
    }
    else
        cerr << "Cannot delete. The record is empty.\n";
}

int instructions()
{
    int choice;

    cout << "\nEnter a choice:\n1 List all tools."
         << "\n2 Update record.\n3 Insert record."
         << "\n4 Delete record.\n5 End program.\n";

    do
    {
        cout << "? ";
        cin >> choice;
    } while (choice < 1 || choice > 5);

    return choice;
}