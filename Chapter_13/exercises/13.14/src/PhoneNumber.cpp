#include "PhoneNumber.hpp"

PhoneNumber::PhoneNumber()
{
    phone[0] = '\0';
    areaCode[0] = '\0';
    exchange[0] = '\0';
    line[0] = '\0';
}

std::ostream &operator<<(std::ostream &output, PhoneNumber &number)
{
    output << "(" << number.areaCode << ") " << number.exchange
           << "-" << number.line << '\n';
    return output;
}

std::istream &operator>>(std::istream &input, PhoneNumber &number)
{
    std::cin.getline(number.phone, 15);

    if (strlen(number.phone) != 14)
        std::cin.clear(std::ios::failbit);

    if (number.phone[1] == '0' || number.phone[6] == '0' ||
        number.phone[1] == '1' || number.phone[6] == '1')
        std::cin.clear(std::ios::failbit);

    if (number.phone[2] != '0' && number.phone[2] != '1')
        std::cin.clear(std::ios::failbit);

    if (!std::cin.fail())
    {
        int loop;
        for (loop = 0; loop <= 2; ++loop)
        {
            number.areaCode[loop] = number.phone[loop + 1];
            number.exchange[loop] = number.phone[loop + 6];
        }

        number.areaCode[loop] = number.exchange[loop] = '\0';

        for (loop = 0; loop <= 3; ++loop)
        {
            number.line[loop] = number.phone[loop + 10];
        }

        number.line[loop] = '\0';
    }
    else
    {
        std::cerr << "Invalid phone number entered.\n";
        exit(1);
    }

    return input;
}