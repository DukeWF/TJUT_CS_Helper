//提取与插入运算符的重载
#include <iostream>
using namespace std;
class A{
	int a;
	public:
		A(int _a=0){
			a=_a;	
		}
		friend ostream& operator<<(ostream &o, A&t);
		friend istream& operator>>(istream &i, A&t);
}; 
ostream& operator<<(ostream &o, A&t){
	o<<t.a;
	return o;
}
istream& operator>>(istream &i, A&t){
	i>>t.a;
	return i;
}
int main(){
	A a(10),b;
	cin>>b;
	cout<<a<<endl;
	cout<<b<<endl;
} 
