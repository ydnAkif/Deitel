#include <iostream>
#include "Invoice.hpp"

int main()
{
    Invoice invoice1("Ham12345",
                     "Hammer", 10, 66);

    std::cout << "Part Number      : "
              << invoice1.getPartNumber()
              << std::endl;

    std::cout << "Part Description : "
              << invoice1.getPartDescription()
              << std::endl;

    std::cout << invoice1.getItemQuantity()
              << " x "
              << invoice1.getPricePerItem()
              << "          = "
              << invoice1.getInvoiceAmount()
              << std::endl;

    return 0;
}