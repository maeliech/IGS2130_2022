#include <iostream>
#include "BankCommon.h"
#include "Account.h"
#include "AccountHandler.h"

using namespace std;


int main(void) {
    AccountHandler manager;
    int choice;
    bool run = true;

    while (run) {
        manager.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            manager.MakeAccount();
            break;
        case bank::DEPOSIT:
            manager.DepositMoney();
            break;
        case bank::WITHDRAW:
            manager.WithdrawMoney();
            break;
        case bank::INQUIRE:
            manager.ShowAccInfo();
            break;
        case bank::EXIT:
            run = false;
            break;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}