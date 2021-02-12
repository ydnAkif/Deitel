#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>

class Package
{
private:
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    int senderZIP;
    std::string recipientName;
    std::string recipientAddress;
    std::string recipientCity;
    std::string recipientState;
    int recipientZIP;
    double weight;
    double costPerOunce;

public:
    Package(const std::string &, const std::string &, const std::string &,
            const std::string &, int, const std::string &, const std::string &,
            const std::string &, const std::string &, int, double, double);
    void setSenderName(const std::string &);
    std::string getSenderName() const;
    void setSenderAddress(const std::string &);
    std::string getSenderAddress() const;
    void setSenderCity(const std::string &);
    std::string getSenderCity() const;
    void setSenderState(const std::string &);
    std::string getSenderState() const;
    void setSenderZIP(int);
    int getSenderZIP() const;
    void setRecipientName(const std::string &);
    std::string getRecipientName() const;
    void setRecipientAddress(const std::string &);
    std::string getRecipientAddress() const;
    void setRecipientCity(const std::string &);
    std::string getRecipientCity() const;
    void setRecipientState(const std::string &);
    std::string getRecipientState() const;
    void setRecipientZIP(int);
    int getRecipientZIP() const;
    void setWeight(double);
    double getWeight() const;
    void setCostPerOunce(double);
    double getCostPerOunce() const;

    virtual double calculateCost() const;

    virtual ~Package();
};

#endif