#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
    std::queue<double> values;

    values.push(3.2);
    values.push(9.8);
    values.push(5.4);

    std::cout << "Popping from values: ";

    while (!values.empty())
    {
        std::cout << values.front() << ' ';
        values.pop();
    }

    std::cout << std::endl;

    return 0;
}
