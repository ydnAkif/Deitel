

int main()
{
    int x, y;
    int *const ptr = &x;

    *ptr = 7; // allowed: *ptr is not const

    ptr = &y; // error: ptr is const; cannot assign to it a new address

    return 0;
}
