#include <iostream>
using namespace std;
class MyObj{
	private:
		int m_n;
	public:
		MyObj(){
			cout<<"Construction '0' "<<endl;
			m_n=0;
		}
		MyObj(int n){
			cout<<"Construction 'n' "<<endl;
			m_n=n;
		}
		MyObj(MyObj &obj){
			cout<<"Copy construction"<<endl;
			m_n=obj.m_n;
		}
		MyObj operator =(const MyObj&obj){
			cout<<"Operator '=' "<<endl;
			m_n=obj.m_n;
			return *this;
		}
		~MyObj(){
			cout<<"Deconstruction"<<endl;
		}
};
MyObj test(int n){
	MyObj aa(n);
	return aa;
}
int main(){
	MyObj bb;
	bb=test(1);
	return 0;
}
