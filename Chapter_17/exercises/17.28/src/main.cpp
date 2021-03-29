#include <iostream>

class InvalidNumberError
{
private:
    std::string errorMessage;

public:
    InvalidNumberError(std::string s) : errorMessage(s) {}
    void print() const { std::cerr << errorMessage; }
};

class TestInvalidNumberError
{
private:
    int idNumber;

public:
    TestInvalidNumberError(int id) : idNumber(id)
    {
        std::cout << "Constructor for object " << idNumber << "\n";

        if (idNumber < 0)
            throw InvalidNumberError("ERROR: Negative ID Number");
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        TestInvalidNumberError valid(10), invalid(-1);
    }
    catch (InvalidNumberError &error)
    {
        error.print();
        std::cerr << '\n';
    }

    return 0;
}
