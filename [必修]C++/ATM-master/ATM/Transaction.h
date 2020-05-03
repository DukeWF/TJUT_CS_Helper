//
//  Transaction.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__Transaction__
#define __ATM__Transaction__

class Screen;
class BankDatabase;

class Transaction
{
public:
    Transaction(int, Screen &, BankDatabase &);
    virtual ~Transaction(){};
    int getAccountNumber() const;
    Screen & getScreen() const;
    BankDatabase & getBankDatabase() const;
    virtual void execute() = 0;
private:
    int accountNumber;
    Screen & screen;
    BankDatabase & bankDatabase;
};

#endif /* defined(__ATM__Transaction__) */
