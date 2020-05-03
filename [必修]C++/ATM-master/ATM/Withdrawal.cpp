//
//  Withdrawal.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "Withdrawal.h"
#include "BankDatabase.h"
#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"

static const int CANCELED = 6;

Withdrawal::Withdrawal(int accountNumber, Screen &screen, BankDatabase &bankDatabase, Keypad &keypad, CashDispenser &cashDispenser):Transaction(accountNumber, screen, bankDatabase), keypad(keypad), cashDispenser(cashDispenser)
{
}

void Withdrawal::execute()
{
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();
    
    bool transactionCanceled = false;
    bool cashDispensed = false;
    
    while (!transactionCanceled && !cashDispensed) {
        amount = displayMenuOfAmounts();
        if (amount != CANCELED)
        {
            double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
            if (amount <= availableBalance) {
                if (cashDispenser.isSufficientCashAvailable(amount)) {
                    bankDatabase.debit(getAccountNumber(), amount);
                    cashDispenser.dispenseCash(amount);
                    cashDispensed = true;
                    screen.displayMessageLine("Please take your cash from cash dispenser.");
                }
                else {
                    screen.displayMessageLine("Insufficient cash available in the ATM.");
                    screen.displayMessageLine("Please choose smaller amount.");
                }
            } else {
                screen.displayMessageLine("Insufficient funds in your account.");
                screen.displayMessageLine("Please choose smaller amount.");
            }
        } else {
            screen.displayMessageLine("Canceling transaction...");
            transactionCanceled = true;
        }
    }
}

int Withdrawal::displayMenuOfAmounts() const
{
    Screen &screen = getScreen();
    int amounts[] = {0, 20, 40, 60, 100, 200};
    int amount = 0;
    
    while (amount == 0) {
        screen.displayMessageLine("");
        screen.displayMessageLine("Withdrawal Options:");
        screen.displayMessageLine("1 - 20");
        screen.displayMessageLine("2 - 40");
        screen.displayMessageLine("3 - 60");
        screen.displayMessageLine("4 - 100");
        screen.displayMessageLine("5 - 200");
        screen.displayMessageLine("6 - Cancel");
        screen.displayMessage("Choose withdrawal options (1-6): ");
        int type = keypad.getInput();
        switch (type) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                amount = amounts[type];
                break;
            case CANCELED:
                amount = CANCELED;
                break;
            default:
                screen.displayMessageLine("Invalid selection. Try again!");
        }
    }
    return amount;
}

