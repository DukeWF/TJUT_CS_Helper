#include <iostream>
using namespace std;
#include <iomanip>
class table{
	protected:
		int i,t;
	public:
		table(int p, int q){//�����Ķ�������ڶ�������ʾ��ֹ�ַ� 
			i=p;
			t=q;
		}
		void ascii();
};
void table::ascii(){
	int k=1;
	for(;i<=t;i++){//ѭ���ڸĶ�����ֹ�ַ� 
		cout<<setw(4)<<i<<" "<<(char)i;
		if((k)%12==0)
			cout<<endl;
			k++;
	}
	cout<<endl;
}
class der_table:public table{
	protected:
		char *c;
	public:
		der_table(int p, int q, char *m):table(p,q){//�β��游������Ķ� 
			c=m;
		}
		void print();
};
void der_table::print(){
	cout<<c<<endl;
	table::ascii();
}
int main(){
	der_table ob1('a','z',"ASCII value --- char");
	ob1.print();
	return 0;
}
