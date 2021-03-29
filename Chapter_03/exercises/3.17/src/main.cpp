#include <iostream>

#include <string>

#include "HealthProfile.hpp"

int main()
{

    HealthProfile hp1("Akif", "Aydin", "Male", 23, 6, 1984, 176, 71);
    hp1.showHealthProfile();
    return 0;
}