//
//  CashDispenser.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__CashDispenser__
#define __ATM__CashDispenser__

class CashDispenser
{
public:
    CashDispenser();
    void dispenseCash(int);
    bool isSufficientCashAvailable(int) const;
private:
    static const int INITIAL_COUNT = 500;
    int count;
};

#endif /* defined(__ATM__CashDispenser__) */
