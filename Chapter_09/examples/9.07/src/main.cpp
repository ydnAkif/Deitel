#include <iostream>
#include "CreateAndDestroy.hpp"

using namespace std;

void create(void);
CreateAndDestroy first(1, "(global before main)");

int main(int argc, const char *argv[])
{
    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second(2, "(local automatic in main)");
    static CreateAndDestroy third(3, "(local static in main)");

    create();

    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;

    CreateAndDestroy fourth(4, "(local automatic in main)");

    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;

    return 0;
}

void create(void)
{
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth(5, "(local automatic in create)");
    static CreateAndDestroy sixth(6, "(local static in create)");
    CreateAndDestroy seventh(7, "(local automatic in create)");
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}