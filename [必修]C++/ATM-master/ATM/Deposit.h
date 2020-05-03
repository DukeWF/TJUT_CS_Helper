//
//  Deposit.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__Deposit__
#define __ATM__Deposit__

#include "Transaction.h"
class Keypad;
class DepositSlot;

class Deposit: public Transaction
{
public:
    Deposit(int, Screen &, BankDatabase &, Keypad &, DepositSlot &);
    virtual void execute();
private:
    double amount;
    Keypad &keypad;
    DepositSlot &depositSlot;
    
    double promptForDepositAmout() const;
};

#endif /* defined(__ATM__Deposit__) */
