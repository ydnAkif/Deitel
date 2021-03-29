#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
void pushElements(T &);

template <typename T>
void popElements(T &);

int main(int argc, char const *argv[])
{
    std::stack<int> intDequeStack;

    std::stack<int, std::vector<int>> intVectorStack;

    std::stack<int, std::list<int>> intListStack;

    std::cout << "Pushing onto intDequeStack: ";
    pushElements(intDequeStack);
    std::cout << std::endl
              << "Pushing onto intVectorStack: ";
    pushElements(intVectorStack);
    std::cout << std::endl
              << "Pushing onto intListStack: ";
    pushElements(intListStack);

    std::cout << std::endl
              << std::endl;

    std::cout << "Popping from intDequeStack: ";
    popElements(intDequeStack);
    std::cout << std::endl
              << "Popping from intVectorStack: ";
    popElements(intVectorStack);
    std::cout << std::endl
              << "Popping from intListStack: ";
    popElements(intListStack);
    std::cout << std::endl;

    return 0;
}

template <typename T>
void pushElements(T &stackRef)
{
    for (int i = 0; i < 10; ++i)
    {
        stackRef.push(i);
        std::cout << stackRef.top() << ' ';
    }
}

template <typename T>
void popElements(T &stackRef)
{
    while (!stackRef.empty())
    {
        std::cout << stackRef.top() << ' ';
        stackRef.pop();
    }
}