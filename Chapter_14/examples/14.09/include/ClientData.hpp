#ifndef CLIENT_DATA_HPP
#define CLIENT_DATA_HPP

#include <string>

class ClientData
{
private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;

public:
    ClientData(int = 0, const std::string & = "",
               const std::string & = "", double = 0.0);

    void setAccountNumber(int);
    int getAccountNumber() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setBalance(double);
    double getBalance() const;
};

#endif