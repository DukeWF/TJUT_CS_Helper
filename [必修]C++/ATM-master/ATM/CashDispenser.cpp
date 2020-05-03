//
//  CashDispenser.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
    count = INITIAL_COUNT;
}

void CashDispenser::dispenseCash(int amount)
{
    int billsDispensed = amount / 20;
    count = count - billsDispensed;
}

bool CashDispenser::isSufficientCashAvailable(int amount) const
{
    int billsDispensed = amount / 20;
    if (count >= billsDispensed)
        return true;
    else
        return false;
}