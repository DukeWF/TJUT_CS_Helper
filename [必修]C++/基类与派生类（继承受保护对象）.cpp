//����������ࣨ�̳��ܱ������� 
#include <iostream>
using namespace std;
//����ʵ�� 
class base{
	protected: 
		int a;
	public:
		base(int t=0):a(t){
			cout<<"A is CONSTRUCTED."<<endl;
		}
		void show(){
			cout<<"A:"<<a<<endl;
		}
		~base(){
			cout<<"A is dead."<<endl;
		} 
		
};
//������ʵ�� 
class derivative:public base{
	protected:
		int b;
	public:
		//ͨ���̳�protected�ڳ�Աʵ�����ݳ�Ա���� 
		derivative(int x, int y):b(y){
			a=x;
			cout<<"B is CONSTRUCTED"<<endl; 
		}
		void show(){
			cout<<"A:"<<a<<endl;
			cout<<"B:"<<b<<endl; 
		}
		~derivative(){
			cout<<"B is dead."<<endl;
		}
};
int main(){
	derivative a(1,2); 
	a.show();
}
