#include <iostream>
#include <cctype>
#include <cstring>
#include "Stack2.hpp"

void converToPostfix(char *const, char *const);
bool isOperator(char);
bool precedence(char, char);

int main(int argc, char const *argv[])
{
    const int MAXSIZE = 100;
    char c, inFix[MAXSIZE], postFix[MAXSIZE];
    int pos = 0;

    std::cout << "Enter the infix expression.\n";

    while ((c = static_cast<char>(std::cin.get())) != '\n')
    {
        if (c != ' ')
            inFix[pos++] = c;
    }

    inFix[pos] = '\0';

    std::cout << "The original infix expression is:\n"
              << inFix << std::endl;

    converToPostfix(inFix, postFix);

    std::cout << "The expression in postfix notation is:\n"
              << postFix << std::endl;

    return 0;
}

void converToPostfix(char *const infix, char *const postfix)
{
    Stack2<char> charStack;
    int infixCount, postfixCount;
    bool higher;
    char popValue, leftParen = '(';

    charStack.push(leftParen);
    charStack.print();
    strcat(infix, ")");

    for (infixCount = 0, postfixCount = 0; charStack.stackTop(); ++infixCount)
    {
        if (isdigit(infix[infixCount]))
            postfix[postfixCount++] = infix[infixCount];
        else if (infix[infixCount] == '(')
        {
            charStack.push(leftParen);
            charStack.print();
        }
        else if (isOperator(infix[infixCount]))
        {
            higher = true;

            while (higher)
            {
                if (isOperator(charStack.stackTop()))
                    if (precedence(charStack.stackTop(), infix[infixCount]))
                    {
                        postfix[postfixCount++] = charStack.pop();
                        charStack.print();
                    }
                    else
                        higher = false;
                else
                    higher = false;
            }

            charStack.push(infix[infixCount]);
            charStack.print();
        }
        else if (infix[infixCount] == ')')
        {
            while ((popValue = charStack.pop()) != '(')
            {
                charStack.print();
                postfix[postfixCount++] = popValue;
            }

            charStack.print();
        }
    }

    postfix[postfixCount] = '\0';
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

bool precedence(char operator1, char operator2)
{
    if (operator1 == '^')
        return true;
    else if (operator2 == '^')
        return false;
    else if (operator1 == '*' || operator1 == '/')
        return true;
    else if (operator1 == '+' || operator1 == '-')
    {
        if (operator2 == '*' || operator2 == '/')
            return false;
        else
            return true;
    }

    return false;
}