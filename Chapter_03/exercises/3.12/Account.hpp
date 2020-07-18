class Account
{
private:
    int accountBalance;

public:
    Account(int);

    int getBalance();

    void credit(int);
    void debit(int);
};