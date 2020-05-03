#include <iostream>
#include <string>
#include "buy.h"
#include "book.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i=0,buyerid,flag;
	book *c[2];
	layfolk b1("林小茶",1,"北京",0);
	honoured_guest b2("帆",2,.6,"郑州",0);
	member b3("钟",3,5,"烟台",0);
	buyer *b[3]=(&b1,&b2&b3);
	book c1("7-302-04504-6","C++程序设计","徐光平","Tianjin University Of Technology",25);
	book c2("7-402-03388-9","数据结构","戴敏","Tianjin University Of Technology",20);
	c[0]=&c1;
	c[1]=&c2;
	cout<<"购书人信息："<<endl<<endl;
	for(i=0;i<3;i++)
		b[i]->display();
	cout<<"图书信息：" <<endl<<endl;
	return 0;
}
