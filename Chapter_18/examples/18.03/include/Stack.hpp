#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

template <typename T>
class Stack
{
private:
    std::deque<T> stack;

public:
    T &top() { return stack.front(); }

    void push(const T &pushValue)
    {
        stack.push_front(pushValue);
    }

    void pop()
    {
        stack.pop_front();
    }

    bool isEmpty() const
    {
        return stack.empty();
    }

    size_t size() const
    {
        return stack.size();
    }
};

#endif