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
	length = len;
	pdata = new int [length+1];
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
		cout<<pdata[i]<<"|";
	cout<<endl;
}
class SortArray:public MyArray{
	public:
		SortArray(int l):MyArray(l){
		}
		SortArray selectiveSort();
		SortArray bubbleSort();
}; 
SortArray SortArray::selectiveSort(){//选择排序 
	int i,j;
	for(i=0;i<length-1;i++){
		int k=i;
		for(j=i+1;j<length;j++){
			if(pdata[k]>pdata[j])
				k=j;
		}
		int t=pdata[k];
		pdata[k]=pdata[i];
		pdata[i]=t;
	}
	return *this;
}
SortArray SortArray::bubbleSort(){
	int i,j;
	for(i=0;i<length-1;i++){
		int k=i;
		for(j=i;j<length-i-1;j++){
			if(pdata[k]>pdata[j]){
				int t=pdata[k];
				pdata[k]=pdata[j];
				pdata[j]=t;
			} 
		} 
	} 
	return *this;
}
int main(){
	SortArray test(10);
	test.input();
	test.selectiveSort();
	test.output();
	test.bubbleSort();
	test.output();
	return 0;
	
}
