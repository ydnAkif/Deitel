void f(const int *);

int main()
{
    int y = 0;
    f(&y);
    return 0;
}

void f(const int *xPtr)
{
    *xPtr = 100; // error: cannot modify a const object
}