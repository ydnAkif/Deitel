#include <iostream>
#include <ctime>
#include "Date.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    Date tdate(12, 31, 2019);
    tdate.printDDD_YYYY();
    tdate.printMM_DD_YY();
    tdate.printEn_US();

    Date tdate2("June 14, 1992");
    tdate2.printEn_US();

    Date tdate3("215 2020");
    tdate3.printEn_US();

    Date tdate4("1/14/2020");
    tdate4.printEn_US();

    Date tdate5(time(0));
    tdate5.printEn_US();

    return 0;
}
