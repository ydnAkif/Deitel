#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("The values in any left subtree"
                        "\nare less than the value in the"
                        "\nparent node and the values in"
                        "\nany right subtree are greater"
                        "\nthan the value in the parent node");

    std::cout << "Original string:\n"
              << string1 << std::endl
              << std::endl;

    string1.erase(62);

    std::cout << "Original string after erase:\n"
              << string1
              << "\nAfter first replacement:\n";
    size_t position = string1.find(" ");

    while (position != std::string::npos)
    {
        string1.replace(position, 1, ".");
        position = string1.find(" ", position + 1);
    }

    std::cout << string1 << "\nAfter second replacement:\n";

    position = string1.find(".");

    while (position != std::string::npos)
    {
        string1.replace(position, 2, "xxxxx;;yyy", 5, 2);
        position = string1.find(".", position + 1);
    }

    std::cout << string1 << std::endl;

    return 0;
}
