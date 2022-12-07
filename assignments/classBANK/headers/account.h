#include <iostream>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    int m_accID;
    int m_balance;
    char* m_cusName;

public:
    Account(int ID, int balance, char* cname);
    Account(const Account& cp);
    ~Account();
    int GetAccID(void) const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo(void) const;
};


#endif ACCOUNT_H
