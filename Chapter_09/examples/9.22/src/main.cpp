// Fig. 9.22: main.cpp
// Friends can access private members of a class
#include <iostream>

using namespace std;

//Cout class definiton
class Count
{
    friend void setX(Count &, int); // friend declaration

private:
    int x{0};

public:
    int getX() const { return x; }
};

// function setX can modify private data of Count
// because setX is declared as a friend of Count (line 10)

void setX(Count &c, int val)
{
    c.x = val; //allowed because setX is a friend of Count
}

int main(int argc, char const *argv[])
{
    Count counter; // create Count object

    cout << "counter.x after instantiation: " << counter.getX() << endl;
    setX(counter, 8); // set x using a friend function
    cout << "counter.x after call to setX friend function: "
         << counter.getX() << endl;
    return 0;
}
