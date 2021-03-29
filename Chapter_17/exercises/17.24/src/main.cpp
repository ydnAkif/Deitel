#include <iostream>

class Object
{
private:
    int value;

public:
    Object(int val) : value(val)
    {
        std::cout << "Object " << value << " constructor\n";
    }
    ~Object()
    {
        std::cout << "Object " << value << " destructor\n";
    }
};

class Error
{
private:
    std::string str;

public:
    Error(std::string s) : str(s)
    {
    }
    void print() const
    {
        std::cerr << '\n'
                  << str << '\n';
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        Object a(1), b(2), c(3);
        std::cout << std::endl;
        throw Error("This is a test exception");
    }
    catch (Error &e)
    {
        e.print();
    }

    return 0;
}
