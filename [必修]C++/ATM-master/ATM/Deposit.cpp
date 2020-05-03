//
//  Deposit.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

static const int CANCELED = 0;

Deposit::Deposit(int accountNumber, Screen &screen, BankDatabase &bankDatabase, Keypad &keypad, DepositSlot &depositSlot):
Transaction(accountNumber, screen, bankDatabase), keypad(keypad), depositSlot(depositSlot)
{
}

void Deposit::execute()
{
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();
    
    amount = promptForDepositAmout();
    
    if (amount != CANCELED) {
        screen.displayMessage("Please insert deposit envelop containing ");
        screen.displayDollarAmount(amount);
        screen.displayMessageLine(" in deposit slot.");
        bool envelopReceived = depositSlot.isEnvelopReceived();
        if (envelopReceived) {
            screen.displayMessageLine("Your envelop has been receiced.");
            bankDatabase.credit(getAccountNumber(), amount);
        } else {
            screen.displayMessageLine("You did not insert the envelop, so the ATM has canceled your transaction.");
        }
    } else {
        screen.displayMessageLine("Canceling transaction...");
    }
}

double Deposit::promptForDepositAmout() const
{
    Screen &screen = getScreen();
    
    screen.displayMessageLine("Please enter deposit amount in CENT (or 0 to cancel):");
    int input = keypad.getInput();
    
    if (input == CANCELED) {
        return CANCELED;
    } else {
        return static_cast<double>(input) / 100;
    }
}