//
//  Account.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__Account__
#define __ATM__Account__

class Account
{
public:
    Account(int, int, double, double);
    int getAccountNumber() const;
    double getAvailableBalance() const;
    double getTotalBalance() const;
    bool validatePin(int) const;
    void credit(double);
    void debit(double);
private:
    int accountNumber;
    int pin;
    double availableBalance;
    double totalBalance;
};

#endif /* defined(__ATM__Account__) */
