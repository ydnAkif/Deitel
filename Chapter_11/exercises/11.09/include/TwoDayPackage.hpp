#ifndef TWO_DAY_PACKAGE_HPP
#define TWO_DAY_PACKAGE_HPP

#include "Package.hpp"

class TwoDayPackage : public Package
{
private:
    double flatFee;

public:
    TwoDayPackage(const std::string &, const std::string &, const std::string &,
                  const std::string &, int, const std::string &, const std::string &,
                  const std::string &, const std::string &, int, double, double, double);

    void setFlatFee(double);
    double getFlatFee() const;

    double calculateCost() const;

    ~TwoDayPackage();
};

#endif