//
//  Screen.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Screen.h"
using namespace std;

void Screen::displayMessage(string message) const
{
    cout << message;
}

void Screen::displayMessageLine(string message) const
{
    cout << message << endl;
}

void Screen::displayDollarAmount(double amount) const
{
    cout << fixed << setprecision(2) << amount;
}
