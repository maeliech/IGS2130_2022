#include "AccountHandler.h"

AccountHandler::AccountHandler() 
    : accNum {0} {}                      //initializing the number of account to 0

AccountHandler::~AccountHandler() {
    delete[]accArr;
}

void AccountHandler::ShowMenu(void) const {
    cout << "-----Menu-----" << endl;
    cout << "1. Make account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Inquire" << endl;
    cout << "5. Exit program" << endl;
}

int AccountHandler::GetAccID(int id) const{
    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            return i;
        }
    }
    return -1;
}

void AccountHandler::MakeAccount(void) {
    int sel;
    if (accNum >= MAX_ACC_NUM) {                                     //checking that they is no more than the maximum number of accounts possible
        cout << "Sorry! Cannot make an account anymore." << endl;
        return;
    }
    cout << "[Make Account]" << endl;
    cout << "[Select Account Type] " << endl;
    cout << " 1. Saving Account " << endl;
    cout << " 2. High Credit Account " << endl;
    cin >> sel;                                                 //sel stands for selection
    cout << " Select: " << sel << endl;
    cout << endl;

    if (sel == 1) {
        MakeSavingAccount();
    }
    else if (sel == 2) {
        MakeHighCreditAccount();
    }
    else {
        cout << "Error: Illegal selection" << endl;
    }
 }



void AccountHandler::DepositMoney(void) {
    int money;
    int id;

    cout << "[Deposit Money]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            accArr[i]->Deposit(money);                           //reusing function
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}
void AccountHandler::WithdrawMoney(void) {
    int money;
    int id;

    cout << "[Wirthdraw money]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            if (accArr[i]->Withdraw(money) == -1) {                //reusing function
                cout << "Not enough balance." << endl << endl;
                return;
            }
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::ShowAccInfo(void) const {
    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowAccInfo();                             //reusing function
        cout << endl;
    }
    return;
}

void AccountHandler::MakeSavingAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance, rate;

    cout << "[Make Saving Account] " << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << "Interest rate: ";                                            
    cin >> rate;
    cout << endl;

    if (GetAccID(id) != -1) { //Not to be confused, here, we get the ID of ACCOUNT in the ARRAY using the Account ID 
        cout << "Error: Existing account ID" << endl;
        return;
    }
    accArr[accNum] = new SavingAccount(id, balance, name, rate);
    accNum++;
}

void AccountHandler::MakeHighCreditAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance, rate, special;

    cout << "[Make High Credit Account] " << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;
    cout << "Interest rate: ";
    cin >> rate;
    cout << endl;
    cout << "Credit Rating (A:1, B:2, C:3): ";                                  //interest rate can be 7, 4 or 2 percent
    cin >> special;
    cout << endl;

    if (GetAccID(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    accArr[accNum] = new HighCreditAccount(id, balance, name, rate, special);
    accNum++;
}