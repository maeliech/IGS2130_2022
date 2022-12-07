#include "SavingAccount.h"

SavingAccount::SavingAccount(int ID, int balance, char* cname, int rate)
    : Account(ID, balance, cname), m_InterestRate{ rate } {}


void SavingAccount::Deposit(int money) {
    Account::Deposit(money);
    Account::Deposit(money * (m_InterestRate / 100.0));           //computing percentage
}