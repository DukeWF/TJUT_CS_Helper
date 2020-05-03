//�����������
#include <iostream>
using namespace std;
//����ʵ�� 
class base{
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
	int b;
	public:
		//ͨ����ʼ����Ա�б���û����˽�ж������ù��캯���� 
		derivative(int x, int y):base(x),b(y){
			cout<<"B is CONSTRUCTED"<<endl; 
		}
		void show(){
			base::show();
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
