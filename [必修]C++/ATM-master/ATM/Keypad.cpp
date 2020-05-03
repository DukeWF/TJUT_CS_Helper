//
//  Keypad.cpp
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#include <iostream>
#include "Keypad.h"
using namespace std;

int Keypad::getInput() const
{
    int input;
    cin >> input;
    return input;
}