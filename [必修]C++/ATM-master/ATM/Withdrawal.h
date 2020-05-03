//
//  Withdrawal.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__Withdrawal__
#define __ATM__Withdrawal__

#include "Transaction.h"
class Keypad;
class CashDispenser;


class Withdrawal: public Transaction
{
public:
    Withdrawal(int, Screen &, BankDatabase &, Keypad &, CashDispenser &);
    virtual void execute();
private:
    int amount;
    Keypad &keypad;
    CashDispenser &cashDispenser;
    int displayMenuOfAmounts() const;
};

#endif /* defined(__ATM__Withdrawal__) */
