#include "TwoDayPackage.hpp"

TwoDayPackage::TwoDayPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                             const std::string &sState, int sZIP, const std::string &rName, const std::string &rAddress,
                             const std::string &rCity, const std::string &rState, int rZIP, double w, double cost, double fee)
    : Package(sName, sAddress, sCity, sState, sZIP,
              rName, rAddress, rCity, rState, rZIP, w, cost)
{
    setFlatFee(fee);
}

void TwoDayPackage::setFlatFee(double fee)
{
    flatFee = (fee < 0.0) ? 0.0 : fee;
}
double TwoDayPackage::getFlatFee() const
{
    return flatFee;
}

double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + getFlatFee();
}

TwoDayPackage::~TwoDayPackage() {}