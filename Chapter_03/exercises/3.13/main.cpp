#include <iostream>
#include "Invoice.hpp"

using namespace std;

int main()
{
    Invoice invoice1("Ham12345", "Hammer", 10, 66);

    cout << "Part Number      : " << invoice1.getPartNumber() << endl;
    cout << "Part Description : " << invoice1.getPartDescription() << endl;
    cout << invoice1.getItemQuantity() << " x " << invoice1.getPricePerItem()
         << "          = " << invoice1.getInvoiceAmount() << endl;

    return 0;
}