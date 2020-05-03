#ifndef BUYER_H
#define BUYER_H
#include <iostream>
#include <string>
using namespace std;

class buyer
{
	public:
		buyer();
		buyer(string n, int b, string a, double p);
		string getbuyname();
		string getaddress();
		double getpay();
		int getid();
		virtual void display()=0;
		virtual void setpay(double =0)=0;
	protected:
		string name;
		int buyerID;
		string address;
		double pay;
};

#endif
