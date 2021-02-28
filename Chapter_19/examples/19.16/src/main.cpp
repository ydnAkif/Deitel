#include <iostream>
#include "Queue.hpp"

int main(int argc, char const *argv[])
{
    Queue<int> intQueue;

    std::cout << "proccessing an integer Queue" << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    int dequeueInteger;

    while (!intQueue.isQueueEmpty())
    {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeued" << std::endl;
        intQueue.printQueue();
    }

    Queue<double> doubleQueue;
    double value = 1.1;

    std::cout << "proccessing a double Queue" << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1;
    }

    double dequeueDouble;

    while (!doubleQueue.isQueueEmpty())
    {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeued" << std::endl;
        doubleQueue.printQueue();
    }

    return 0;
}
