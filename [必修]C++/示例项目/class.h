//ԭ����������Ķ��� 
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


