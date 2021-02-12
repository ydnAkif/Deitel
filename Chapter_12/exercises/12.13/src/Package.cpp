#include "Package.hpp"

Package::Package(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                 const std::string &sState, int sZIP, const std::string &rName, const std::string &rAddress,
                 const std::string &rCity, const std::string &rState, int rZIP, double w, double cost)
    : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP),
      recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP)

{
    setWeight(w);
    setCostPerOunce(cost);
}

void Package::setSenderName(const std::string &name)
{
    senderName = name;
}

std::string Package::getSenderName() const
{
    return senderName;
}
void Package::setSenderAddress(const std::string &address)
{
    senderAddress = address;
}
std::string Package::getSenderAddress() const
{
    return senderAddress;
}
void Package::setSenderCity(const std::string &city)
{
    senderCity = city;
}
std::string Package::getSenderCity() const
{
    return senderCity;
}
void Package::setSenderState(const std::string &state)
{
    senderState = state;
}
std::string Package::getSenderState() const
{
    return senderState;
}
void Package::setSenderZIP(int zip)
{
    senderZIP = zip;
}
int Package::getSenderZIP() const
{
    return senderZIP;
}
void Package::setRecipientName(const std::string &name)
{
    recipientName = name;
}
std::string Package::getRecipientName() const
{
    return recipientName;
}
void Package::setRecipientAddress(const std::string &address)
{
    recipientAddress = address;
}
std::string Package::getRecipientAddress() const
{
    return recipientAddress;
}
void Package::setRecipientCity(const std::string &city)
{
    recipientCity = city;
}
std::string Package::getRecipientCity() const
{
    return recipientCity;
}
void Package::setRecipientState(const std::string &state)
{
    recipientState = state;
}
std::string Package::getRecipientState() const
{
    return recipientState;
}
void Package::setRecipientZIP(int zip)
{
    recipientZIP = zip;
}
int Package::getRecipientZIP() const
{
    return recipientZIP;
}
void Package::setWeight(double w)
{
    weight = (w < 0.0) ? 0.0 : w;
}
double Package::getWeight() const
{
    return weight;
}
void Package::setCostPerOunce(double cost)
{
    costPerOunce = (cost < 0.0) ? 0.0 : cost;
}
double Package::getCostPerOunce() const
{
    return costPerOunce;
}

double Package::calculateCost() const
{
    return getWeight() * getCostPerOunce();
}

Package::~Package() {}