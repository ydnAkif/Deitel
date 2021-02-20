#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::deque<double> values;
    std::ostream_iterator<double> output(std::cout, " ");

    values.push_front(2.2);
    values.push_front(3.5);
    values.push_back(1.1);

    std::cout << "values contains: ";

    for (size_t i = 0; i < values.size(); ++i)
        std::cout << values[i] << ' ';

    values.pop_front();
    std::cout << "\nAfter pop_front(), values contains: ";
    std::copy(values.cbegin(), values.cend(), output);

    values[1] = 5.4;

    std::cout << "\nAfter values[1]= 5.4, values contains: ";
    std::copy(values.cbegin(), values.cend(), output);
    std::cout << std::endl;

    return 0;
}