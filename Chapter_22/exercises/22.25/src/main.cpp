#include <iostream>

int isDigit(int);
int isAplha(int);
int isAlNum(int);
int isLower(int);
int isUpper(int);
int isSpace(int);
int isPunct(int);
int isPrint(int);
int isGraph(int);
int toLower(int);
int toUpper(int);

int main(int argc, char const *argv[])
{
    int v;
    char a;
    char headers[] = "According to ";
    const char *names[] = {"isDigit ", "isApha ", "isAlNum ", "isLower ",
                           "isUpper ", "isSpace ", "isPunct ", "isPrint ", "isGraph ",
                           "toLower ", "toUpper "};
    const char *names2[] = {"digit", "letter", "letter/digit", "lowercase",
                            "uppercase", "space", "punctuation", "print", "graph",
                            "converted lowercase", "converted uppercase"};
    int (*f[])(int) = {isDigit, isAplha, isAlNum, isLower,
                       isUpper, isSpace, isPunct, isPrint,
                       isGraph, toLower, toUpper};

    std::cout << "Enter a character: ";
    std::cin >> a;

    for (int k = 0; k < 11; ++k)
    {
        v = (*f[k])(static_cast<int>(a));
        std::cout.write(headers, 13);
        std::cout << names[k] << a << (!v ? " is not a " : " is a ")
                  << names2[k] << " character\n";
    }

    return 0;
}

int isDigit(int c)
{
    return (c >= 48 && c <= 57) ? 1 : 0;
}
int isAplha(int c)
{
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ? 1 : 0;
}
int isAlNum(int c)
{
    return (isDigit(c) == 1 || isAplha(c) == 1) ? 1 : 0;
}
int isLower(int c)
{
    return (c >= 97 && c <= 122) ? 1 : 0;
}
int isUpper(int c)
{
    return (c >= 65 && c <= 90) ? 1 : 0;
}
int isSpace(int c)
{
    return ((c == 32) || (c >= 9 && c <= 13)) ? 1 : 0;
}
int isPunct(int c)
{
    return (isAlNum(c) == 0 && isSpace(c) == 0) ? 1 : 0;
}
int isPrint(int c)
{
    return (c >= 32 && c <= 126) ? 1 : 0;
}
int isGraph(int c)
{
    return (c >= 33 && c <= 126) ? 1 : 0;
}
int toLower(int c)
{
    return (isUpper(c) == 1) ? c + 32 : c;
}
int toUpper(int c)
{
    return (isLower(c) == 1) ? c - 32 : c;
}
