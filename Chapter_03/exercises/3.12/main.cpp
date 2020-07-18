#include <iostream>
#include "Account.hpp"
using namespace std;
int main()
{

    Account account1(500);
    Account account2(1500);

    cout << " account1 initial balance is " << account1.getBalance() << endl;
    cout << " account2 initial balance is " << account2.getBalance() << endl;
    account1.credit(150);
    account1.debit(50);
    account2.credit(500);
    account2.debit(2000);

    cout << " account1 new balance is " << account1.getBalance() << endl;
    cout << " account2 new balance is " << account2.getBalance() << endl;
    return 0;
}