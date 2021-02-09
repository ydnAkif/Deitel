#include "OvernightPackage.hpp"

OvernightPackage::OvernightPackage(const std::string &sName, const std::string &sAddress,
                                   const std::string &sCity, const std::string &sState,
                                   int sZIP, const std::string &rName,
                                   const std::string &rAddress, const std::string &rCity,
                                   const std::string &rState, int rZIP, double w, double cost, double fee)
    : Package(sName, sAddress, sCity, sState, sZIP,
              rName, rAddress, rCity, rState, rZIP, w, cost)
{
    setOvernightFeePerOunce(fee);
}

void OvernightPackage::setOvernightFeePerOunce(double overnightFee)
{
    overnightFeePerOunce = (overnightFee < 0.0) ? 0.0 : overnightFee;
}
double OvernightPackage::getOvernightFeePerOunce() const
{
    return overnightFeePerOunce;
}

double OvernightPackage::calculateCost() const
{
    return Package::getWeight() * (Package::getCostPerOunce() + getOvernightFeePerOunce());
}

OvernightPackage::~OvernightPackage()
{
}