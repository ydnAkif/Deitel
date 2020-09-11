#include <iostream>

void hanoiTowers(int, int, int, int);

int main()
{
    int n, s{1}, d{3}, a{2};

    std::cout << " A program to solve Hanoi Tower used n disks"
              << std::endl
              << std::endl;

    std::cout << "Enter the disk number: ";
    std::cin >> n;

    hanoiTowers(n, s, d, a);

    return 0;
}

void hanoiTowers(int n, int source, int destination, int auxilary)
{
    if (n == 1)
    {
        std::cout << source
                  << " --> "
                  << destination
                  << std::endl;
        return;
    }

    hanoiTowers(n - 1, source, auxilary, destination);

    std::cout << source
              << " --> "
              << destination
              << std::endl;

    hanoiTowers(n - 1, auxilary, destination, source);
}