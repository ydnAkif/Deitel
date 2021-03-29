#include <iostream>
#include <iomanip>
#include "Package.hpp"
#include "TwoDayPackage.hpp"
#include "OvernightPackage.hpp"

int main(int argc, char const *argv[])
{
    Package package1("Lou Brown", "1 Main St", "Boston", "MA", 11111,
                     "Mary Simith", "7 Elm St", "New York", "NY", 22222, 8.5, .5);

    TwoDayPackage package2("Lisa Klein", "5 Broadway", "Somerville", "MA", 33333,
                           "Bob George", "21 Pine Rd", "Cambridge", "MA", 44444, 10.5, .65, 2.0);

    OvernightPackage package3("Ed Lewis", "2 Oak St", "Boston", "MA", 55555,
                              "Don Kelly", "9 Main St", "Denver", "CO", 66666, 12.25, .7, .25);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Package 1:\n\nSender:\n"
              << package1.getSenderName()
              << '\n'
              << package1.getSenderAddress()
              << '\n'
              << package1.getSenderCity()
              << ", "
              << package1.getSenderState()
              << ' ' << package1.getSenderZIP();
    std::cout << "\n\nRecipient:\n"
              << package1.getRecipientName()
              << '\n'
              << package1.getRecipientAddress()
              << '\n'
              << package1.getRecipientCity()
              << ", "
              << package1.getRecipientState()
              << ' ' << package1.getRecipientZIP();
    std::cout << "\n\nCost: $" << package1.calculateCost() << std::endl
              << std::endl;

    std::cout << "Package 2:\n\nSender:\n"
              << package2.getSenderName()
              << '\n'
              << package2.getSenderAddress()
              << '\n'
              << package2.getSenderCity()
              << ", "
              << package2.getSenderState()
              << ' ' << package2.getSenderZIP();
    std::cout << "\n\nRecipient:\n"
              << package2.getRecipientName()
              << '\n'
              << package2.getRecipientAddress()
              << '\n'
              << package2.getRecipientCity()
              << ", "
              << package2.getRecipientState()
              << ' ' << package2.getRecipientZIP();
    std::cout << "\n\nCost: $" << package2.calculateCost() << std::endl
              << std::endl;

    std::cout << "Package 3:\n\nSender:\n"
              << package3.getSenderName()
              << '\n'
              << package3.getSenderAddress()
              << '\n'
              << package3.getSenderCity()
              << ", "
              << package3.getSenderState()
              << ' ' << package3.getSenderZIP();
    std::cout << "\n\nRecipient:\n"
              << package3.getRecipientName()
              << '\n'
              << package3.getRecipientAddress()
              << '\n'
              << package3.getRecipientCity()
              << ", "
              << package3.getRecipientState()
              << ' ' << package3.getRecipientZIP();
    std::cout << "\n\nCost: $" << package3.calculateCost() << std::endl
              << std::endl;

    return 0;
}
