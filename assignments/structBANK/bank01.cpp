#include <iostream>
#include <cstring>

#ifndef _BANK_H_
#define _BANK_H_

using namespace std;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
void DeleteAccount(void);
void DeleteAllAcc(void);
int GetAccIdx(int);

enum class bank {MAKE = 1, DEPOSIT, WITHDRAW, DELETE, ALLD, TRANSFER, INQUIRE, EXIT};
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

typedef struct 
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

#endif

//___________________________________________________________________________________//


Account accArr[MAX_ACC_NUM];
int accNum = 0;

void ShowMenu(void){
    cout << "-----Menu-----" << endl;
    cout << "1. Make account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Delete account" << endl;
    cout << "5. Delete all accounts" << endl;
    cout << "6. Transfer" << endl;
    cout << "7. Display all" << endl;
    cout << "8. Exit program" << endl;
}

void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;

    if (accNum >= MAX_ACC_NUM){
        cout << "Sorry! Cannot make an account anymore." << endl;
        return;
    }
    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    if (GetAccIdx(id) != -1){
        cout << "Error: Existing account ID" << endl;
        return;
    }
    
    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void){
    int money;
    int id;
    cout <<"[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum ; i++){
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
    int money;
    int id;
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i< accNum; i++){
        if (accArr[i].accID == id){
            if (accArr[i].balance < money){
                cout << "Not enough balance." << endl << endl;
                return;
            }
            
            accArr[i].balance -= money;
            cout << "Withdrawal completed." << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void DeleteAccount(void){
    int id;
    cout << "ID of the account to be deleted: ";
    cin >> id;
    for (int i = 0; i< accNum; i++){
        if (accArr[i].accID == id){
            if (accArr[i].balance == 0){ //checking that the account is empty to not loose money
                accArr[i].accID = 0 ;
                cout << "Account deleted." << endl << endl;
                return;
            }
            cout << "Account must be empty, please make a withdrawal." << endl << endl; //acc must be empty!
            return;
        }
    }
}

void DeleteAllAcc(void){
    int reply;
    cout << "All accounts are about to be deleted (even if they are not empty)... Are you sure? Type 1 for yes and 0 for no. ";
    cin >> reply;
    if (reply == 1){
        for (int i = 0; i< accNum; i++){              
                accArr[i].balance = 0; //resetting balance and ID. Name will be changed when someone takes the same ID
                accArr[i].accID = 0;
                return;
        }
    }
    cout << "Action cancelled." <<endl << endl;
    return;
}

void Transfer(){
    int send, receive, amount;
    cout << "Enter sender account ID: ";
    cin >> send;
    cout << "Enter receiver account ID: ";
    cin >> receive;
    cout << "Enter amount of money to transfer: ";
    cin >> amount;

    for (int i = 0; i< accNum; i++){
        if (accArr[i].accID == send){
            for (int j = 0; j< accNum; j++){
                if (accArr[j].accID == receive){
                    if (accArr[i].balance < amount){
                        cout << "Not enough balance on sender account." << endl << endl;
                        return;
                    }
                accArr[i].balance -= amount; //taking the money off
                accArr[j].balance += amount; //adding the money to the account
                cout << "Withdrawal completed." << endl << endl;
                return;
                }
                cout << "Receiver ID is not valid." << endl << endl;
            }
        }
        cout << "Sender ID is not valid." << endl << endl;
    }
}

void ShowAllAccInfo(void){
    for (int i = 0; i < accNum; i++){
        cout << "Account ID: " << accArr[i].accID << endl;
        cout << "Name: " << accArr[i].cusName << endl;
        cout << "Balance: " << accArr[i].balance << endl;
    }
}

int GetAccIdx(int id){
    for (int i = 0; i < accNum; i++){
        if (accArr[i].accID == id){
            return i;
        }
    }
    return -1;
}

//___________________________________________________________________________________//

int main(void){
    int choice;

    while (1){
        ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            MakeAccount();
            break;
        case bank::DEPOSIT:
            DepositMoney();
            break;
        case bank::WITHDRAW:
            WithdrawMoney();
            break;
        case bank::DELETE:
            DeleteAccount();
            break;
        case bank::ALLD:
            DeleteAllAcc();
            break;
        case bank::TRANSFER:
            Transfer();
            break;
        case bank::INQUIRE:
            ShowAllAccInfo();
            break;
        case bank::EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
