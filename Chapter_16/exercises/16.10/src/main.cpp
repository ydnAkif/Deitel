#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> v;
    std::ifstream inputFile("../data.txt", std::ios::in);

    if (!inputFile)
    {
        std::cerr << "Unable to open data.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::istream_iterator<int> input(inputFile);
    std::ostream_iterator<int> output(std::cout, " ");

    std::copy(input, std::istream_iterator<int>(), std::back_inserter(v));

    std::copy(v.cbegin(), v.cend(), output);
    std::cout << std::endl;

    return 0;
}
