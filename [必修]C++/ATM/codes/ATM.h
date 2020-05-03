#ifndef ATM_H
#define ATM_H
#define CLS system("cls")
#define PAUSE system("pause")

#include "customer.h"
#include <conio.h>

class ATM{
	public:
//�������캯������������customer�����ڲ������ԣ�α������ver 1.0 
		ATM(customer& c):cm(c){
			show_information();
		}
//�˵���������ʾ�˵��뽻������
		void welcome();
		void menu();
//���ܺ�����ʵ�ֶ�Ӧ����	
		void deposit();
		void withdraw();
		void transfer();
		void change_pw();
//��ʾ��������ʽ�������Ӧ����
		void show_deposit();
		void show_deposit(int mo);
		void show_withdraw();
		void show_withdraw(int mo);
		void show_withdraw(int mo, int i);
		void show_transfer(int i);
		void show_transfer(int mo, int id, int i);
		void show_money();
		void show_menu();
		void show_information();
//�жϺ������ж��߼�����		
		int judge_num();//�ж���100�����������ջ����ȷ��ֵ 
	protected:
		customer cm;
};

#endif
