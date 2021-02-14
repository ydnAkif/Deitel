#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    char *string = "test";

    cout << "Value of string is                        : " << string << '\n'
         << "Value of static_cast<void *>(string) is   : " << static_cast<void *>(string) << '\n'
         /*         << "Value of static_cast<char>(string) is     : " << static_cast<char>(string) << '\n'
         << "Value of static_cast<int>(string> is      : " << static_cast<int>(string) << '\n'
         << "Value of static_cast<long>(string) is     : " << static_cast<long>(string) << '\n'
         << "Value of static_cast<short>(string) is    : " << static_cast<short>(string) << '\n'
         << "Value of static_cast<unsigned>(string) is : " << static_cast<unsigned>(string) */
         << endl;

    return 0;
}
