//
//  BankDatabase.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "BankDatabase.h"
#include <stddef.h>

BankDatabase::BankDatabase()
{
    Account account1(12345, 54321, 1000.00, 1200.00);
    Account account2(23456, 65432, 500.00, 800.00);
    
    accounts.push_back(account1);
    accounts.push_back(account2);
}

double BankDatabase::getAvailableBalance(int accountNumber) 
{
    Account * const account = getAccount(accountNumber);
    return account->getAvailableBalance();
}

double BankDatabase::getTotalBalance(int accountNumber)
{
    Account * const account = getAccount(accountNumber);
    return account->getTotalBalance();
}

bool BankDatabase::authenticateUser(int accountNumber, int pin)
{
    Account * const account = getAccount(accountNumber);
    if (account != NULL)
        return account->validatePin(pin);
    else
        return false;
}

void BankDatabase::credit(int accountNumber, double amount)
{
    Account * account = getAccount(accountNumber);
    account->credit(amount);
}

void BankDatabase::debit(int accountNumber, double amount)
{
    Account * account = getAccount(accountNumber);
    account->debit(amount);
}

Account * BankDatabase::getAccount(int accountNumber)
{
    for (size_t index = 0; index < accounts.size(); ++index) {
        if (accounts[index].getAccountNumber() == accountNumber)
            return &accounts[index];
    }
    return NULL;
}
