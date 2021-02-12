#ifndef OVERNIGHT_PACKAGE_HPP
#define OVERNIGHT_PACKAGE_HPP

#include "Package.hpp"

class OvernightPackage : public Package
{
private:
    double overnightFeePerOunce;

public:
    OvernightPackage(const std::string &, const std::string &, const std::string &,
                     const std::string &, int, const std::string &, const std::string &,
                     const std::string &, const std::string &, int, double, double, double);

    void setOvernightFeePerOunce(double);
    double getOvernightFeePerOunce() const;

    virtual double calculateCost() const;

    ~OvernightPackage();
};

#endif