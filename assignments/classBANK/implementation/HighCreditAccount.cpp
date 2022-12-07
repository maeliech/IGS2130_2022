#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cname, int rate, int special)
    : SavingAccount(ID, balance, cname, rate), m_SpecialRate{ special } {}                          

void HighCreditAccount::Deposit(int money) {
    Account::Deposit(money);
    Account::Deposit(money * (m_SpecialRate / 100.0));            //computing the percentage
}

