#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
#include <iomanip>

using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

int main(int argc, char const *argv[])
{
    ofstream outFile("../size.dat");

    if (!outFile)
    {
        cerr << "Unable to open \"size.dat\".\n";
        exit(EXIT_FAILURE);
    }

    outFile << "Data type" << setw(16) << "Size\nchar"
            << setw(21) << sizeof(char)
            << "\nunsigned char" << setw(12) << sizeof(unsigned char)
            << "\nshort int" << setw(16) << sizeof(short int)
            << "\nunsigned short int" << setw(7) << sizeof(unsigned short int)
            << "\nint" << setw(22) << sizeof(int) << endl;

    outFile << "unsigned int" << setw(13) << sizeof(unsigned int)
            << "\nlong int" << setw(17) << sizeof(long int)
            << "\nunsigned long int" << setw(8) << sizeof(unsigned long int)
            << "\nfloat" << setw(20) << sizeof(float)
            << "\ndouble" << setw(19) << sizeof(double)
            << "\nlong double" << setw(14) << sizeof(long double) << endl;

    outFile.close();

    return 0;
}
