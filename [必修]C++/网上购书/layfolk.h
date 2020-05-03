#ifndef LAYFOLK_H
#define LAYFOLK_H

#include "buyer.h"

class layfolk : public buyer
{
	public:
		layfolk(string n, int b, double r, string a,double p);
		void display();
		void setpay(double p);
};

#endif
