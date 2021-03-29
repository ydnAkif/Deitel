#include <array>
#include <iostream>
#include <stdexcept>

using namespace std;

void outputArray7(const array<int, 7> &);
void outputArray10(const array<int, 10> &);

int main()
{

    array<int, 7> integers1{};
    array<int, 10> integers2{};

    cout << "Size of array integers1 is " << integers1.size()
         << "\narray after initialization: ";
    outputArray7(integers1);

    cout << "\nSize of array integers2 is " << integers2.size()
         << "\narray after initialization: ";
    outputArray10(integers2);

    cout << "\nEnter 17 integers:" << endl;
    for (int &item : integers1)
        cin >> item;
    for (int &item : integers2)
        cin >> item;

    cout << "\nAfter input, the arrays contain:\nintegers1: ";
    outputArray7(integers1);
    cout << "integers2: ";
    outputArray10(integers2);

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (std::equal(std::begin(integers1), std::end(integers1), std::begin(integers2)))
        cout << "integers1 and integers2 are equal" << endl;
    else
        cout << "integers1 and integers2 are not equal" << endl;

    array<int, 7> integers3{integers1};

    cout << "\nSize of array integers3 is " << integers3.size()
         << "\narray after initialization: ";
    outputArray7(integers3);

    cout << "\nintegers1[ 5 ] is " << integers1[5];

    cout << "\n\nAssigning 1000 to integers1[ 5 ]" << endl;
    integers1.at(5) = 1000;
    cout << "integers1: ";
    outputArray7(integers1);

    try
    {
        cout << "\nAttempt to display integers1.at( 15 )" << endl;
        cout << integers1.at(15) << endl;
    }
    catch (out_of_range &ex)
    {
        cerr << "An exception occured: " << ex.what() << endl;
    }

    return 0;
}

void outputArray7(const array<int, 7> &a)
{
    for (const int &item : a)
        cout << item << ' ';
    cout << endl;
}

void outputArray10(const array<int, 10> &a)
{
    for (const int &item : a)
        cout << item << ' ';
    cout << endl;
}
