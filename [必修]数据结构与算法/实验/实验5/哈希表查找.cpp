/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��5-03����ϣ�����
//�汾��0.5
//˵��������
/************************************************************************/
#include <iostream>
#include <string>
using namespace std;
typedef struct Hash{
	string str;
}Hash;
typedef Hash* HashList;
int su;
//����̽����ɢ�з������ͻ 
int LP(HashList H, int temp, string name, int n){
	int t=temp+1;
	while(t!=temp){
		if(H[t].str.compare(" ")){
			H[temp].str=name;
			return 1;
		}
		if(t==n-1) t=0;
		else t++;
	}
	return -1;
}
//����̽�鷨���� 
bool LP_Find(HashList H, int temp, string name, int n){
	int t=temp+1;
	while(t!=temp){
		if(H[t].str.compare(name)) return 1;
		if(t==n-1) t=0;
		else t++;
	}
	return 0;
}
//��ɢ�е�ַ 
int Hash_Address(string str){
	int temp;
	temp=(str[0]-'a')/su;
	return temp;
}
//��ʼ����ϣ�� 
int init_Hash(HashList H, int num){
	string name;
	int temp;
	for(int i=0;i<num;i++){
		cin>>name;
		temp=Hash_Address(name);
		if(H[temp].str.compare(" ")) H[temp].str=name;//�������� 
		else if(LP(H,temp,name,num)!=1) return -1;//�����쳣����
		else continue;
	}
	return 1;
}
//��ѯ
int query(HashList H, int q, int n){
	string name;
	for(int i=0;i<q;i++){
		cin>>name;
		int temp=Hash_Address(name);
		if(H[temp].str.compare(name)){
			cout<<"1"<<endl;
		}
		else if(LP_Find(H,temp,name,n)){
			cout<<"1"<<endl;			
		}
		else{
			cout<<"0"<<endl;		
		}
	}
}
bool isPrimMethod(int n){
	bool isPrim=1; //isPrim�����ж�һ�����Ƿ�Ϊ����
	if(n==2||n==3) return 1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	} 
	return 1;
} 
int getsu(int n){
	for(int i=n;i>=2;i--){
		if(isPrimMethod(i)) return i;
	} 
}
int main(){
	int n,q;
	cin>>n>>q;
	su=getsu(n);
	
	Hash H[n];
	init_Hash(H,n);	
	query(H,q,n);
	return 0;
}
