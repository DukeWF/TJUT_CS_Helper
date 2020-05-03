#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
class book
{
	public:
		book();
		book(string b_id, string b_n, string au, string pu, double pr);
		void display();
		string getbook_ID();
		string getbook_name();
		string getauthor();
		string getpublishing();
		double getprice();
	protected:
		string book_ID;
		string book_name;
		string author;
		string publishing;
		double price;
		
};	

#endif
