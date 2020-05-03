#include<iostream>
#include<cmath>
using namespace std;
#define MAX 20

bool query(string a, string b);
int main(){
	int n,q;
	string str[MAX];
	cin>>n>>q;
	int index=0;
	while(index < n){
		cin>>str[index];
		index++;
	}
	int Sindex=0;
	while(Sindex<q){
		string temp;
		int ab;
		cin>>temp; 
		for(int i=0;i<n;i++){
			ab=str[i].length()-temp.length();
			if(ab<=1&&ab>=-1){
				if(query(str[i], temp)){
					cout<<"1"<<endl;
					break;
				}	
			}
			if(i==n-1) cout<<"0"<<endl;
		}
		Sindex ++;
	}
	return 0;
}
bool query(string a, string b){
	int different=0;
	if(a.length()-b.length()==0){
		for(int i = 0; i < a.length(); i++){
			if(a[i]!=b[i]) different++;
		} 
		if(different<=1) return 1;
	}
	else if(a.length()-b.length()==1){
		for(int i=0,j=0;a[i]!='\0'&&b[j]!='\0';i++){
			char x=a[i], y=b[i];
			if(a[i] != b[j]) different++;
			else j++;
		} 
		if(different <= 1) return 1;
	} 
	else if(b.length()-a.length()==1){
		for(int i=0,j=0;b[i]!='\0'&&a[j]!='\0';i++){
			if(b[i] != a[j]) different++;
			else j++;		
		}
		if(different<=1) return 1;
	}
	return 0;
}
