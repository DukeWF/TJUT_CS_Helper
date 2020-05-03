#ifndef MEMBER_H
#define MEMBER_H

#include "buyer.h"

class member:public buyer
{
	public:
		member(string n, int b, int l, string a, double p);
		void display();
		void setpay(double p);
	protected:
		int leaguer_grade;
};

#endif
