#include "Account.h"

Account::Account(int ID, int balance, char* cname)
    : m_accID{ ID }, m_balance{ balance }                  //initializing the account
{   
    int len = strlen(cname) + 1;
    m_cusName = new char[len];
    strcpy_s(m_cusName, len, cname);
}

// copy constructor created following the example in the course
Account::Account(const Account& cp) : m_accID{ cp.m_accID }, m_balance{ cp.m_balance }
{
    int len = strlen(cp.m_cusName) + 1;
    m_cusName = new char[len];
    strcpy_s(m_cusName, len, cp.m_cusName);
}

Account::~Account() {
    delete[]m_cusName;
}

int Account::GetAccID(void) const {
    return m_accID;
}

void Account::Deposit(int money) {
    if (money > 0)
        m_balance += money;
}

int Account::Withdraw(int money) {
    if ((money < 0) || (money > m_balance))      //checking if the operation is possible with the amount of money on account
        return -1;
    m_balance -= money;
    return money;
}

void Account::ShowAccInfo(void) const {
    
    std::cout << "Account ID: " << m_accID << std::endl;
    std::cout << "Name: " << m_cusName << std::endl;
    std::cout << "Balance: " << m_balance << std::endl << std::endl;
}
