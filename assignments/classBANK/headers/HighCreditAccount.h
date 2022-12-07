#include <iostream>
#include "Account.h"
#include "SavingAccount.h"

using namespace std;

#ifndef HIGHCREDIT_ACCOUNT_H
#define HIGHCREDIT_ACCOUNT_H

class HighCreditAccount : public SavingAccount {
private:
    int m_SpecialRate;
public:
    HighCreditAccount(int ID, int balance, char* cname, int rate, int special);
    virtual void Deposit(int money);  
};

#endif
