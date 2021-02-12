#include <iostream>
#include <iomanip>
#include <vector>

#include "Package.hpp"
#include "TwoDayPackage.hpp"
#include "OvernightPackage.hpp"

int main(int argc, char const *argv[])
{
    std::vector<Package *> packages(3);
    packages[0] = new Package("Lou Brown", "1 Main St", "Boston", "MA", 11111,
                              "Mary Simith", "7 Elm St", "New York", "NY", 22222, 8.5, .5);

    packages[1] = new TwoDayPackage("Lisa Klein", "5 Broadway", "Somerville", "MA", 33333,
                                    "Bob George", "21 Pine Rd", "Cambridge", "MA", 44444, 10.5, .65, 2.0);

    packages[2] = new OvernightPackage("Ed Lewis", "2 Oak St", "Boston", "MA", 55555,
                                       "Don Kelly", "9 Main St", "Denver", "CO", 66666, 12.25, .7, .25);

    double totalShippingCoast = 0.0;

    std::cout << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < packages.size(); ++i)
    {
        std::cout << "Package " << i + 1 << "\n\nSender:\n"
                  << packages[i]->getSenderName() << '\n'
                  << packages[i]->getSenderAddress() << '\n'
                  << packages[i]->getSenderCity() << ", "
                  << packages[i]->getRecipientState() << ' '
                  << packages[i]->getSenderZIP();
        std::cout << "\n\nRecipient:\n"
                  << packages[i]->getRecipientName()
                  << '\n'
                  << packages[i]->getRecipientAddress() << '\n'
                  << packages[i]->getRecipientCity() << ", "
                  << packages[i]->getRecipientState() << ' '
                  << packages[i]->getRecipientZIP();
        double cost = packages[i]->calculateCost();
        std::cout << "\n\nCost: $" << cost << "\n\n";
        totalShippingCoast += cost;
    }

    std::cout << "Total shipping cost: $" << totalShippingCoast << std::endl;

    return 0;
}
