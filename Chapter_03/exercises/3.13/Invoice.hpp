#include <iostream>
#include <string>

class Invoice
{
private:
    std::string partNumber;
    std::string partDescription;
    int itemQuantity;
    int pricePerItem;

public:
    Invoice(std::string, std::string, int, int);

    //Setters
    void setPartNumber(std::string);
    void setPartDescription(std::string);
    void setItemQuantity(int);
    void setPricePerItem(int);

    //Getters

    std::string getPartNumber() const;
    std::string getPartDescription() const;
    int getItemQuantity() const;
    int getPricePerItem() const;
    int getInvoiceAmount() const;
};
