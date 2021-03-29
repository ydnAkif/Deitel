#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <Stack.hpp>

int evaluatePostfixExpression(char *const);
int calculate(int, int, char);

int main(int argc, char const *argv[])
{
    char expression[100], c;
    int answer, i = 0;

    std::cout << "Enter a postfix expression:\n";

    while ((c = static_cast<char>(std::cin.get())) != '\n')
    {
        if (c != ' ')
            expression[i++] = c;
    }

    expression[i] = '\0';

    answer = evaluatePostfixExpression(expression);

    std::cout << "The value of the expression is: " << answer << std::endl;

    return 0;
}

int evaluatePostfixExpression(char *const expr)
{
    int i, popVal1, popVal2, pushVal;
    Stack<int> intStack;
    char c;

    strcat(expr, ")");

    for (i = 0; (c = expr[i]) != ')'; ++i)
    {
        if (isdigit(expr[i]))
        {
            pushVal = c - '0';
            intStack.push(pushVal);
            intStack.print();
        }
        else
        {
            popVal2 = intStack.pop();
            intStack.print();
            popVal1 = intStack.pop();
            intStack.print();
            pushVal = calculate(popVal1, popVal2, expr[i]);
            intStack.push(pushVal);
            intStack.print();
        }
    }

    return intStack.pop();
}

int calculate(int op1, int op2, char oper)
{
    switch (oper)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return static_cast<int>(pow(op1, op2));
    }

    return 0;
}
