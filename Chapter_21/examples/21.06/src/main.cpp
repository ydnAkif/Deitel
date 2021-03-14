#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("noon is 12 pm; midnight is not.");

    int location;

    std::cout << "Original string:\n"
              << string1
              << "\n\n(find) \"is\" was found at: " << string1.find("is")
              << "\n(rfind) \"is\" was found at: " << string1.rfind("is");

    location = string1.find_first_of("misop");
    std::cout << "\n\n(find_first_of) found '" << string1[location]
              << "' from the group \"misop\" at: " << location;

    location = string1.find_last_of("misop");
    std::cout << "\n\n(find_last_of) found '" << string1[location]
              << "' from the group \"misop\" at: " << location;

    location = string1.find_first_not_of("noi spm");
    std::cout << "\n\n(find_first_not_of) found '" << string1[location]
              << "' is not contained in \"noi spm\" and was found at: " << location;

    location = string1.find_first_not_of("12noi spm");
    std::cout << "\n\n(find_first_not_of) found '" << string1[location]
              << "' is not contained in \"12noi spm\" and was found at: " << location << std::endl;

    location = string1.find_first_not_of("noon is 12pm; midnight is not.");
    std::cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
              << " returned: " << location << std::endl;

    return 0;
}
