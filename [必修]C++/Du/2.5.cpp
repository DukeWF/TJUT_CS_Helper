#include <iostream>
using namespace std;
 
class magic{				//声明魔方阵类magic
private:
	int m[4][4];
	int step;
	int first;
	int sumj;

public:
	void getdata(int a,int b){
		first=a;
		step=b;
	}			//输入初值成员函数
	void setfirstmagic();	//设置初始魔方成员函数
	int generate();			//生成最终魔方成员函数
	int printmagic();		//显示魔方成员函数
};
void magic::setfirstmagic(){
	int i,j;
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			m[i][j]=first;
			first+=step;
		}
	}
}
int magic::generate(){
	int k;
	sumj=m[0][0]+m[3][3];
	for(k=0;k<=3;k++){
		m[k][k]=sumj-m[k][k];
		m[k][3-k]=sumj-m[k][3-k];
	}
	return 0;
}
int magic::printmagic(){
	int i,j;
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			cout<<m[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
	return 0;
}
int main(){
	int f,s;
	cout<<"初始值：";
	cin>>f;
	cout<<"差值：";
	cin>>s;
	magic m;
	m.getdata(f,s);
	m.setfirstmagic();
	cout<<"初始魔方阵："<<endl;
	m.printmagic();
	m.generate();
	cout<<"生成魔方阵："<<endl;
	m.printmagic();
	return 0;
}
