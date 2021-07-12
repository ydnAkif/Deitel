/*******************************************************************************
 
 Exercises 3.13

 (Invoice Class) Create a class called Invoice that a hardware store might use 
 to represent an invoice for an item sold at the store. An Invoice should include 
 four data members—a part num- ber (type string), a part description (type string), 
 a quantity of the item being purchased (type int) and a price per item (type int). 
 [Note: In subsequent chapters, we’ll use numbers that contain decimal points 
 (e.g., 2.75)—called floating-point values—to represent dollar amounts.] Your class 
 should have a constructor that initializes the four data members. A constructor 
 that receives multiple arguments is defined with the form:
 
 ClassName( TypeName1 parameterName1, TypeName2 parameterName2, ... )
 Provide a set and a get function for each data member. In addition, provide a 
 member function named getInvoiceAmount that calculates the invoice amount 
 (i.e., multiplies the quantity by the price per item), then returns the amount as 
 an int value. If the quantity is not positive, it should be set to 0. If the price 
 per item is not positive, it should be set to 0. Write a test program that 
 demon- strates class Invoice’s capabilities.

*******************************************************************************/

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