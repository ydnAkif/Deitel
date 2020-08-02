#include "GasMileage.hpp"

GasMileage::GasMileage()
{
    milesDriven = 0.0f;
    totalMilesDriven = 0.0f;
    galloonsUsed = 0.0f;
    totalGalloonUsed = 0.0f;
    tripMPG = 0.0f;
    totalMPG = 0.0f;
}

//Setters

void GasMileage::setMilesDriven()
{
    milesDriven = 0.0f;
    std::cout << "Enter miles driven (-1 to quit)   : ";
    std::cin >> milesDriven;
}
void GasMileage::setTotalMilesDriven()
{
    totalMilesDriven += getMilesDriven();
}
void GasMileage::setGallonsUsed()
{
    galloonsUsed = 0.0f;

    std::cout << "Enter gallons used                : ";
    std::cin >> galloonsUsed;
}
void GasMileage::setTotalGalloonsUsed()
{
    totalGalloonUsed += getGallonsUsed();
}
void GasMileage::setTripMPG()
{
    tripMPG = 0.0f;
    tripMPG = getMilesDriven() / getGallonsUsed();
}

void GasMileage::setTotalMPG()
{
    totalMPG = getTotalMilesDriven() / getTotalGallonsUsed();
}

//Getters

double GasMileage::getMilesDriven() const
{
    return milesDriven;
}
double GasMileage::getTotalMilesDriven() const
{
    return totalMilesDriven;
}

double GasMileage::getGallonsUsed() const
{
    return galloonsUsed;
}
double GasMileage::getTotalGallonsUsed() const
{
    return totalGalloonUsed;
}
double GasMileage::getTripMPG() const
{
    return tripMPG;
}

double GasMileage::getTotalMPG() const
{
    return totalMPG;
}

void GasMileage::run()
{
    setMilesDriven();
    if (getMilesDriven() != -1)
    {
        setTotalMilesDriven();
        setGallonsUsed();
        setTotalGalloonsUsed();
        setTripMPG();
        setTotalMPG();

        std::cout << "MPG this trip                     : "
                  << std::setprecision(6)
                  << std::fixed
                  << getTripMPG()
                  << std::endl
                  << "Total MPG                         : "
                  << getTotalMPG()
                  << std::endl
                  << std::endl;
    }
}