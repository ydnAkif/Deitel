#pragma once

template <typename T>

struct Questions
{
    T num1;
    T num2;

    void init(T n1, T n2)
    {
        num1 = (n1 > n2) ? n1 : n2;
        num2 = (n1 > n2) ? n2 : n1;
    }

    T multiply()
    {
        return (num1 * num2);
    }

    T add()
    {
        return (num1 + num2);
    }

    T subtract()
    {
        return (num1 - num2);
    }

    T divide()
    {
        num1 = (num1 == 0 ? 1 : num1);
        num2 = (num2 == 0 ? 1 : num2);

        double scale = 0.01;
        return static_cast<int>((num1 / num2) / scale) * scale;
    }
};
