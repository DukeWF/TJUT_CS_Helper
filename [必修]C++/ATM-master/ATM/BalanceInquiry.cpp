//
//  BalanceInquiry.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

BalanceInquiry::BalanceInquiry(int accountNumber, Screen &screen, BankDatabase &bankDatabase)
:Transaction(accountNumber, screen, bankDatabase)
{
}

void BalanceInquiry::execute()
{
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();
    
    double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
    double totalBalance = bankDatabase.getTotalBalance(getAccountNumber());
    
    screen.displayMessageLine("");
    screen.displayMessageLine("Balance information:");
    screen.displayMessage("-Available Balance: ");
    screen.displayDollarAmount(availableBalance);
    screen.displayMessageLine("");
    screen.displayMessage("-Total Balance: ");
    screen.displayDollarAmount(totalBalance);
    screen.displayMessageLine("");
}
