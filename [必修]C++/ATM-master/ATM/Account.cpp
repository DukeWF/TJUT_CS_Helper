//
//  Account.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "Account.h"

Account::Account(int accountNumber, int pin, double availableBalance, double totalBalance):
accountNumber(accountNumber), pin(pin), availableBalance(availableBalance), totalBalance(totalBalance)
{
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getAvailableBalance() const
{
    return availableBalance;
}

double Account::getTotalBalance() const
{
    return totalBalance;
}

bool Account::validatePin(int userPin) const
{
    if (userPin == pin)
        return true;
    else
        return false;
}

void Account::credit(double amount)
{
    totalBalance = totalBalance + amount;
}

void Account::debit(double amount)
{
    availableBalance = availableBalance - amount;
    totalBalance = totalBalance - amount;
}