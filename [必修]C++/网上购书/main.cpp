#include <iostream>
#include <string>
#include "buy.h"
#include "book.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i=0,buyerid,flag;
	book *c[2];
	layfolk b1("��С��",1,"����",0);
	honoured_guest b2("��",2,.6,"֣��",0);
	member b3("��",3,5,"��̨",0);
	buyer *b[3]=(&b1,&b2&b3);
	book c1("7-302-04504-6","C++�������","���ƽ","Tianjin University Of Technology",25);
	book c2("7-402-03388-9","���ݽṹ","����","Tianjin University Of Technology",20);
	c[0]=&c1;
	c[1]=&c2;
	cout<<"��������Ϣ��"<<endl<<endl;
	for(i=0;i<3;i++)
		b[i]->display();
	cout<<"ͼ����Ϣ��" <<endl<<endl;
	return 0;
}
