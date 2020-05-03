//
//  BalanceInquiry.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__BalanceInquiry__
#define __ATM__BalanceInquiry__

#include "Transaction.h"

class BalanceInquiry: public Transaction
{
public:
    BalanceInquiry(int, Screen &, BankDatabase &);
    virtual void execute();
};

#endif /* defined(__ATM__BalanceInquiry__) */
