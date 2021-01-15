// Fig. 9.24: main.cpp
// Using the this pointer to refer to object members.
#include <iostream>

using namespace std;

class Test
{
private:
    int x{0};

public:
    explicit Test(int);
    void print() const;
};

// constructor
Test::Test(int value) : x{value} {} // initialize x to value

// print x using implicit then explicit this pointers;
// the parantheses around *this are required
void Test::print() const
{
    // implicitly use the this pointer to access the member x
    cout << "        x = " << x;

    //emplicitly use the this pointer and the arrow operator
    // to access the member x
    cout << "\n  this->x = " << this->x;

    // emplicitly use the dereferenced this pointer and
    // the dot operator to access the member x
    cout << "\n(*this).x = " << (*this).x << endl;
}

int main(int argc, char const *argv[])
{
    Test testObject{12}; // instantiate and initialize testObject
    testObject.print();
    return 0;
}
