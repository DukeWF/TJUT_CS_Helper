#include <iostream>
#include <string>
using namespace std;
string name[100];
void init_Hash(int num);
void query(int q, int num);
int main(){
	int n,q;
	cin>>n>>q;
	
	init_Hash(n);
	query(q,n);
	
	return 0;
}
void init_Hash(int num){
	for(int i=0;i<num;i++){
		cin>>name[i];
	}
	return;
}
void query(int q,int num){
	string nm;
	for(int i=0;i<q;i++){
		cin>>nm;
		for(int j=0;j<num;j++){
			if(nm==name[j]){
				cout<<"1"<<endl;
				break;
			}
			if(j==num-1){
				cout<<"0"<<endl;
				break;
			}
		}
	}
	return;
}
