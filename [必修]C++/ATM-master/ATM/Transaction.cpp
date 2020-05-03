//
//  Transaction.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"

Transaction::Transaction(int accountNumber, Screen &screen, BankDatabase &bankDatabase):
accountNumber(accountNumber), screen(screen), bankDatabase(bankDatabase)
{
}

int Transaction::getAccountNumber() const
{
    return accountNumber;
}

Screen & Transaction::getScreen() const
{
    return screen;
}

BankDatabase & Transaction::getBankDatabase() const
{
    return bankDatabase;
}
