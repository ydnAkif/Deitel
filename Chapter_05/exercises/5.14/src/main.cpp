#include <iostream>
#include <iomanip>

double getPrice(int, int);
int main()
{
    double total{0.0f};
    int product{0}, quantity{0};

    std::cout << "Program to add retail prices for 5 products."
              << std::endl
              << std::endl;

    while (product != -1)
    {
        std::cout << "Enter the product number and quantity sold (-1 to quit): ";

        std::cin >> product;

        if (product != -1)
        {
            std::cin >> quantity;

            total += getPrice(product, quantity);

            std::cout << "Running total: $"
                      << std::fixed
                      << std::setprecision(2)
                      << total
                      << std::endl;
        }
    }

    return 0;
}

double getPrice(int product, int quantity)
{
    switch (product)
    {
    case 1:
        return 2.98 * quantity;
        break;
    case 2:
        return 4.50 * quantity;
        break;
    case 3:
        return 9.98 * quantity;
        break;
    case 4:
        return 4.49 * quantity;
        break;
    case 5:
        return 6.87 * quantity;
        break;
    default:
        std::cout << "Incorrect product number entered." << std::endl;
        return 0.0f;
        break;
    }
}