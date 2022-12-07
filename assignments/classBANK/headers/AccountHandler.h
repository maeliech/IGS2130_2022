#include "BankCommon.h"
#include "Account.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
#include<iostream>

using namespace std;

#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

class AccountHandler {
private:
    Account* accArr[MAX_ACC_NUM]; //Account array
    int accNum = 0;               // # of accounts

    int GetAccID(int id) const;

public:
    AccountHandler();
    ~AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAccInfo(void) const;
    void MakeSavingAccount(void);
    void MakeHighCreditAccount(void);
};

#endif