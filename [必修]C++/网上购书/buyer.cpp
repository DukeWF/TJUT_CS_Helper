#include "buyer.h"

buyer::buyer(){
	cout<<"Name:";
	cin>>name;
	cout<<"ID:";
	cin>>buyerID;
	cout<<"Address:";
	cin>>address;
	cout<<"Pay:";
	cin>>pay;
}
buyer::buyer(string n, int b, string a, double p){
	name=n;
	buyerID=b;
	address=a;
	pay=p;
}
string buyer::getbuyname(){
	return name;
}

string buyer::getaddress(){
	return address;
}
double buyer::getpay(){
	return pay;
}
int buyer::getid(){
	return buyerID;
}
//virtual void buyer::display()=0{
//	cout<<"List:\n"<<"Name:"<<name<<endl<<"ID:"<<buyerID<<endl<<"Address:"<<address<<endl<<"Pay:"<<pay<<endl<<endl; 
//}
//virtual void buyer::setpay(double =0)=0{
//}


