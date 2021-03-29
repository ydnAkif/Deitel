#include <iostream>

using namespace std;

int mystery2(const char *);

int main(int argc, char const *argv[])
{
    char string1[80];

    cout << "Enter  a string: ";
    cin >> string1;

    cout << mystery2(string1) << endl;

    return 0;
}

//Count string
int mystery2(const char *s)
{
    unsigned int x;
    for (x = 0; *s != '\0'; ++s)
        ++x;
    return x;
}