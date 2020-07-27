#include <iostream>
#include <iomanip>

class GasMileage
{
private:
    double milesDriven, galloonsUsed, tripMPG,
        totalMPG, totalMilesDriven, totalGalloonUsed;

public:
    GasMileage();

    //Setters

    void setMilesDriven();
    void setTotalMilesDriven();
    void setGallonsUsed();
    void setTotalGalloonsUsed();
    void setTripMPG();
    void setTotalMPG();

    //Getters

    double getMilesDriven() const;
    double getTotalMilesDriven() const;
    double getGallonsUsed() const;
    double getTotalGallonsUsed() const;
    double getTripMPG() const;
    double getTotalMPG() const;

    void run();
};
