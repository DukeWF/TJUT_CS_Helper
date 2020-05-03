#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class customer
{
	public:
//构造函数-construction 
		customer();
		customer(string id,string nm,double mo):ID(id),name(nm),money(mo){password=set_pw();}
//初始化函数：设置密码与金额变更 
		int set_pw();
		void set_pw(int pw);
		void set_money(int mo);
//Get函数：获取私有对象信息 
		string get_ID();
		double get_money();
		string get_name();
		int get_pw();
//Judge函数：判断逻辑正误 
		int judge_pw();
		int judge_pw(int i);
	protected:
 		string ID;
		string name;
		int password;
		double money;
};
#endif
