#include "book.h"
book::book(){
	book_ID="";
	book_name="";
	author="";
	publishing="";
	price=0; 
}
book::book(string b_id, string b_n, string au, string pu, double pr):book_ID(b_id), book_name(b_n), author(au), publishing(pu), price(pr){
}
void book::display(){
	cout<<"��ţ�"<<book_ID<<"\t";
	cout<<"������"<<book_name<<"\t";
	cout<<"���ߣ�"<<author<<"\t;";
	cout<<"�����磺"<<publishing<<"\t";
	cout<<"���ۣ�" <<price<<"\t";
}
string book::getbook_ID(){	
	return book_ID;
}
string book::getbook_name(){
	return book_name;
}
string book::getauthor(){
	return author;
}
string book::getpublishing(){
	return publishing;
}
double book::getprice(){
	return price;
}
