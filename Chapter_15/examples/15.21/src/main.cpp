#include <iostream>

#include <queue>

int main(int argc, char const *argv[])
{
    std::priority_queue<double> priorities;

    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);

    std::cout << "Popping from priorities: ";

    while (!priorities.empty())
    {
        std::cout << priorities.top() << ' ';
        priorities.pop();
    }

    std::cout << std::endl;

    return 0;
}
