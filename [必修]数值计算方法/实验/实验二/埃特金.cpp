#include <iostream>
using namespace std;
double T[n],L[n];
void Start();
int main(){
	int n,i = 1,j = 1;
	float a;
	cout<<"节点数：";
	cin>>n;	
	cout<<"横纵坐标："<<endl;
	while(i <= n){
		cin>>T[i]>>L[i];
		i++;
	} 
	cout<<"输入要插值的X坐标：";
	cin>>a; 
	Start();
	cout<<"y的坐标："<<L[n]<<endl;
}
void Start(){
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++) L[j]=(a-T[i])*L[j]/(T[j]-T[i])+(a-T[j])*L[i]/(T[i]-T[j]);		
		cout<<'('<<T[i]<<','<<L[i]<<')'<<endl; 
	}
}
