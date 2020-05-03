//
//  Screen.h
//  ATM
//
//  Created by Xeasony on 11/23/14.
//  Copyright (c) 2014 Xeasony. All rights reserved.
//

#ifndef __ATM__Screen__
#define __ATM__Screen__

#include <string>
using namespace std;

class Screen
{
public:
    void displayMessage(string) const;
    void displayMessageLine(string) const;
    void displayDollarAmount(double) const;
};

#endif /* defined(__ATM__Screen__) */
