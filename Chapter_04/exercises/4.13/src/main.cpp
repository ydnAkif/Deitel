#include "GasMileage.hpp"

static const int QUIT = -1;
int main()
{
    GasMileage gm;
    while (gm.getMilesDriven() != QUIT)
    {
        gm.run();
    }

    return 0;
}
