#include <iostream>
using namespace std;
 
class magic{				//����ħ������magic
private:
	int m[4][4];
	int step;
	int first;
	int sumj;

public:
	void getdata(int a,int b){
		first=a;
		step=b;
	}			//�����ֵ��Ա����
	void setfirstmagic();	//���ó�ʼħ����Ա����
	int generate();			//��������ħ����Ա����
	int printmagic();		//��ʾħ����Ա����
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
	cout<<"��ʼֵ��";
	cin>>f;
	cout<<"��ֵ��";
	cin>>s;
	magic m;
	m.getdata(f,s);
	m.setfirstmagic();
	cout<<"��ʼħ����"<<endl;
	m.printmagic();
	m.generate();
	cout<<"����ħ����"<<endl;
	m.printmagic();
	return 0;
}
