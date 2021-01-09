#include <iostream>
#include "Date.hpp"
#include "Employee.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Date birth(23, 6, 1984);
    Date hire(6, 2, 2012);
    Employee manager("Akif", "Aydin", birth, hire);

    cout << endl;

    manager.print();

    return 0;
}
