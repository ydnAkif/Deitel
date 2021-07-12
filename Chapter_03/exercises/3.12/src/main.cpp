/*******************************************************************************
 
 Exercises 3.12

 (Account Class) Create an Account class that a bank might use to represent 
 customers’ bank accounts. Include a data member of type int to represent 
 the account balance. [Note: In subsequent chapters, we’ll use numbers that 
 contain decimal points (e.g., 2.75)—called floating-point values— to represent
 dollar amounts.] Provide a constructor that receives an initial balance and 
 uses it to ini- tialize the data member. The constructor should validate the 
 initial balance to ensure that it’s greater than or equal to 0. If not, set 
 the balance to 0 and display an error message indicating that the initial 
 balance was invalid. Provide three member functions. Member function credit 
 should add an amount to the current balance. Member function debit should 
 withdraw money from the Account and ensure that the debit amount does not exceed
 the Account’s balance. If it does, the balance should be left unchanged and the 
 function should print a message indicating "Debit amount exceed- ed account 
 balance." Member function getBalance should return the current balance. Create 
 a program that creates two Account objects and tests the member functions of 
 class Account.

*******************************************************************************/

#include <iostream>
#include "Account.hpp"

int main()
{

    Account account1(500);
    Account account2(1500);

    std::cout << " account1 initial balance is "
              << account1.getBalance()
              << std::endl;
    std::cout << " account2 initial balance is "
              << account2.getBalance()
              << std::endl;

    account1.credit(150);
    account1.debit(50);
    account2.credit(500);
    account2.debit(2000);

    std::cout << " account1 new balance is "
              << account1.getBalance()
              << std::endl;
    std::cout << " account2 new balance is "
              << account2.getBalance()
              << std::endl;
    return 0;
}