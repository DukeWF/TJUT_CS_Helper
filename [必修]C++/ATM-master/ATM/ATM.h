//
//  ATM.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__ATM__
#define __ATM__ATM__

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"
class Transaction;

class ATM
{
public:
    ATM();
    void run();
private:
    bool isAuthenticated;
    int currentAccountNumber;
    Screen screen;
    Keypad keypad;
    CashDispenser cashDispenser;
    DepositSlot depositSlot;
    BankDatabase bankDatabase;
    
    void authenticateUser();
    void performTransactions();
    int displayMainMenu() const;
    Transaction *createTransaction(int);
};

#endif /* defined(__ATM__ATM__) */
