//�����Լ���������� 
#include <iostream>
using namespace std;
class coord{
	int x,y;
	public:
		coord(int _x=0, int _y=0):x(_x),y(_y){};//��Ա�б�ʽ��ʼ��
		coord operator++();
		coord operator++(int dummy); 
		void show();
};
coord coord::operator++(){//������thisָ�� 
	this->x++;
	this->y++;
	return *this;//��������
} 
coord coord::operator++(int dummy){//demmy����Ϊ��ǲ�����û��ʵ���ô��� 
	coord t=*this;
	this->x++;
	this->y++;
	return t;//����ԭֵ 
}
void coord::show(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}
int main(){
	coord c1(1,2),c2(3,4);
	c1.show();
	c2=c1++;
	c1.show();
	c2.show();
	 
} 
