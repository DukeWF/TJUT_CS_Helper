//
//  ATM.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"

enum MenuOption { BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };

ATM::ATM():isAuthenticated(false), currentAccountNumber(0)
{
}

void ATM::run()
{
    while (true)
    {
        while (!isAuthenticated) {
            screen.displayMessageLine("");
            screen.displayMessageLine("Wellcome");
            authenticateUser();
        }
        performTransactions();
        isAuthenticated = false;
        currentAccountNumber = 0;
        screen.displayMessageLine("");
        screen.displayMessageLine("Thanks you, good bye!");
    }
}

void ATM::authenticateUser()
{
    screen.displayMessageLine("");
    screen.displayMessageLine("Please enter your account number:");
    int accountNumber = keypad.getInput();
    screen.displayMessageLine("");
    screen.displayMessageLine("Please enter your pin:");
    int pin = keypad.getInput();
    
    isAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);
    
    if (isAuthenticated)
        currentAccountNumber = accountNumber;
    else {
        screen.displayMessageLine("");
        screen.displayMessage("Invalid account number or pin. Please try again!");
    }
}

void ATM::performTransactions()
{
    Transaction * transactionPtr;
    bool exited = false;
    
    while (!exited) {
        int type = displayMainMenu();
        
        switch (type) {
            case BALANCE_INQUIRY:
            case WITHDRAWAL:
            case DEPOSIT:
                transactionPtr = createTransaction(type);
                transactionPtr->execute();
                delete transactionPtr;
                break;
            case EXIT:
                screen.displayMessageLine("");
                screen.displayMessageLine("Existing the system...");
                exited = true;
                break;
            default:
                screen.displayMessageLine("");
                screen.displayMessageLine("Invalid option. Try Again!");
        }
    }
    
}

int ATM::displayMainMenu() const
{
    screen.displayMessageLine("");
    screen.displayMessageLine("Main menu:");
    screen.displayMessageLine("1-Display Balance");
    screen.displayMessageLine("2-Withdraw Cash");
    screen.displayMessageLine("3-Deposit Funds");
    screen.displayMessageLine("4-Exit");
    screen.displayMessage("Enter choice:");
    return keypad.getInput();
}

Transaction * ATM::createTransaction(int type)
{
    Transaction * transactionPtr;
    
    switch (type) {
        case BALANCE_INQUIRY:
            transactionPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
            break;
        case WITHDRAWAL:
            transactionPtr = new Withdrawal(currentAccountNumber, screen, bankDatabase, keypad, cashDispenser);
            break;
        case DEPOSIT:
            transactionPtr = new Deposit(currentAccountNumber, screen, bankDatabase, keypad, depositSlot);
            break;
        default:
            break;
    }
    return transactionPtr;
}
