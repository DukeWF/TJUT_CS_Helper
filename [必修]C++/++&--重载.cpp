//自增自减运算符重载 
#include <iostream>
using namespace std;
class coord{
	int x,y;
	public:
		coord(int _x=0, int _y=0):x(_x),y(_y){};//成员列表方式初始化
		coord operator++();
		coord operator++(int dummy); 
		void show();
};
coord coord::operator++(){//※利用this指针 
	this->x++;
	this->y++;
	return *this;//返回自身
} 
coord coord::operator++(int dummy){//demmy参数为标记参数（没有实际用处） 
	coord t=*this;
	this->x++;
	this->y++;
	return t;//返回原值 
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
