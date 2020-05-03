#include <iostream>
#include <cmath> 
using namespace std; 

int main(){
	int a[4];
	int j=0;
	int i;
	for(i=5;i>=1;i-=2,j++){
		a[j]=i;
	}
	int b[4-1];
	int k=0;
	for(i=1+2,k=0;i<=5;i+=2,k++){
		b[k]=i;
	}
	int flag;
	for(i=1,j=0;i<=3;i++,j++){
		if(j==4) break;
		for(flag=i;flag<=a[j];flag++){
			cout<<"*";
		}
		if(i!=3) cout<<endl<<" ";
	}
//	for(i=1;i<=3-1;i++,k++){
//		if(k==3) break;
//		for(flag=1;flag!=b[1]-b[0];flag++){
//			cout<<" ";
//		}
//		for(flag=i;flag>b[k];flag++){
//			cout<<"*"; 
//		}
//		cout<<endl;
//	} 
	return 0;
} 
