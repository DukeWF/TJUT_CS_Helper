#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef struct point{
	double x,y;
}point;
point p[6];
void init_map(){
	double a,b;
	for(int i=0;i<6;i++){
		cout<<"请 输入节点"<<(i+1)<<':';
		cin>>a>>b;
		p[i].x=a;
		p[i].y=b;
	}
}
void print(point *pt, int n){
	for(int i=0;i<n;i++){
		cout<<'('<<pt[i].x<<','<<pt[i].y<<')'<<endl;
	}
}
void find_point(point *pt){
	int i,j,flag,n;
	double x,t1,t2=1000;
	bool visited[6]={false};
	cout<<"请 输入节点数量n(2≤n≤6):";
	cin>>n;
	cout<<"请 输入插值点x:";
	cin>>x;
	for(i=0;i<n;i++){
		for(j=0;j<6;j++){
			if(!visited[j]) t1=fabs(p[j].x-x);
			if(t1<t2){
				t2=t1;
				flag=j;				
			}
		}
		visited[j]=true;
		pt[i]=p[flag];
	}
	print(pt,n);
}

void Lagrange(){
	
}
int main(){
	point pt[6];
	init_map();
	find_point(pt);
	Lagrange();
} 
