//1.定义一个基类，基类存储一组整数 
#include <iostream> 
using namespace std;
class MyArray{
	protected:
		int *pdata;
		int length;
	public:
		MyArray(int len);
		~MyArray();
		void input();
		void output();
};
MyArray::MyArray(int len){
	if(len>0){
		pdata = new int [len];
		length = len;
	}
	else{
		cout<<"ERROR!"<<endl;
		exit(-1);
	}
}
MyArray::~MyArray(){
	delete pdata;
}
void MyArray::input(){
	for(int i=0;i<length;i++){
		cin>>pdata[i];
	}
}
void MyArray::output(){
	for(int i=0;i<length;i++)
		cout<<pdata[i];
}
int main(){
	MyArray test(-1);
	test.input();
	test.output();
	return 0;
	
}
