//
//  BankDatabase.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__BankDatabase__
#define __ATM__BankDatabase__

#include <vector>
#include "Account.h"
using namespace std;

class BankDatabase
{
public:
    BankDatabase();
    double getAvailableBalance(int);
    double getTotalBalance(int);
    bool authenticateUser(int, int);
    void credit(int, double);
    void debit(int, double);
private:    
    Account * getAccount(int);
    vector<Account> accounts;
};

#endif /* defined(__ATM__BankDatabase__) */
