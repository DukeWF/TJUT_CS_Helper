#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class customer
{
	public:
//���캯��-construction 
		customer();
		customer(string id,string nm,double mo):ID(id),name(nm),money(mo){password=set_pw();}
//��ʼ���������������������� 
		int set_pw();
		void set_pw(int pw);
		void set_money(int mo);
//Get��������ȡ˽�ж�����Ϣ 
		string get_ID();
		double get_money();
		string get_name();
		int get_pw();
//Judge�������ж��߼����� 
		int judge_pw();
		int judge_pw(int i);
	protected:
 		string ID;
		string name;
		int password;
		double money;
};
#endif
