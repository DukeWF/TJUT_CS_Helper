#include <iostream>
using namespace std;
#include <iomanip>
class table{
	protected:
		int i,t;
	public:
		table(int p, int q){//参数改动：加入第二参数表示截止字符 
			i=p;
			t=q;
		}
		void ascii();
};
void table::ascii(){
	int k=1;
	for(;i<=t;i++){//循环节改动：截止字符 
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
		der_table(int p, int q, char *m):table(p,q){//形参随父类参数改动 
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
