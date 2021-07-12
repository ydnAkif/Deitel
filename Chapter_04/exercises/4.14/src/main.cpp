/******************************************************************************

Exercises 4.14

(Credit Limits) Develop a C++ program that will determine whether a department 
store customer has exceeded the credit limit on a charge account. For each 
customer, the following facts are available:
a) Account number (an integer)
b) Balanceatthebeginningofthemonth
c) Total of all items charged by this customer this month
d) Total of all credits applied to this customer's account this month
e) Allowed credit limit
The program should use a while statement to input each of these facts, calculate 
the new balance (= beginning balance + charges – credits) and determine whether 
the new balance exceeds the customer’s credit limit. For those customers whose 
credit limit is exceeded, the program should display the customer’s account number, 
credit limit, new balance and the message “Credit Limit Exceeded.”

******************************************************************************/

#include "CreditLimits.hpp"

const static int QUIT = -1;

int main(int argc, char const *argv[])
{
    CreditLimits cl1;

    while (cl1.getAccountNumber() != QUIT)
    {
        cl1.run();
    }

    return 0;
}
