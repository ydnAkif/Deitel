#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("STRINGS");
    const char *ptr1 = nullptr;
    size_t length = string1.size();
    char *ptr2 = new char[length + 1];

    string1.copy(ptr2, length, 0);
    ptr2[length] = '\0';

    std::cout << "string string1 is " << string1
              << "\nstring1 converted to a pointer-based string is " << string1.c_str() << "\nptr1 is ";

    ptr1 = string1.data();

    for (size_t i = 0; i < length; ++i)
        std::cout << *(ptr1 + i);

    std::cout << "\nptr2 is " << ptr2 << std::endl;
    delete[] ptr2;

    return 0;
}
