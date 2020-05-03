#ifndef HONOURED_GUEST_H
#define HONOURED_GUEST_H

#include "buyer.h"

class honoured_guest : public buyer
{
	public:
		honoured_guest(string n, int b, double r, string a, double p);
		void display();
		void setpay(double p);
	protected:
		double discount_rate;
};

#endif
