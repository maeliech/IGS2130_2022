#include "Account.h"

using namespace std;

#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

class SavingAccount : public Account {
private:
    int m_InterestRate; // %
public:
    SavingAccount(int ID, int balance, char* cname, int rate);
    virtual void Deposit(int money);
};

#endif


