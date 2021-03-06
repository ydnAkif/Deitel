#include "Invoice.hpp"

Invoice::Invoice(std::string number,
                 std::string description,
                 int quantity, int price)
{
    setPartNumber(number);
    setPartDescription(description);
    setItemQuantity(quantity);
    setPricePerItem(price);
}

//Setters

void Invoice::setPartNumber(std::string number)
{
    partNumber = number;
}
void Invoice::setPartDescription(std::string description)
{
    partDescription = description;
}
void Invoice::setItemQuantity(int quantity)
{
    itemQuantity = (quantity > 0) ? quantity : 0;
}
void Invoice::setPricePerItem(int price)
{
    pricePerItem = (price > 0) ? price : 0;
}

//Getters

std::string Invoice::getPartNumber() const
{
    return partNumber;
}
std::string Invoice::getPartDescription() const
{
    return partDescription;
}

int Invoice::getItemQuantity() const
{
    return itemQuantity;
}
int Invoice::getPricePerItem() const
{
    return pricePerItem;
}

int Invoice::getInvoiceAmount() const
{
    return (getItemQuantity() * getPricePerItem());
}