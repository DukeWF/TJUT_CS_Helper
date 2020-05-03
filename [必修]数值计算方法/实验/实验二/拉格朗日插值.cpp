#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <map>
using namespace std;
typedef struct point{
	double x, y;
};
map<int, point>J,m;
double a,b,x,n;
void Start(int n);
double result(double x, map<int, point> m);
int init();

int main()
{
	int n=init();	
	Start(n);	
	double d=result(x,m);
	for(auto &i : m) cout<<'('<<i.second.x<<','<<i.second.y<<')'<<endl;
	cout<<"拉格朗日插值结果："<<d<<endl;
}

int init(){	
	for (int i=1; i<=6; i++){
		cout<<"请输入节点"<<i<<':';
		cin>>a>>b;
		J.insert({ i,{a,b} });
	}
	
	cout<<"请输入节点数量n(2≤n≤6):";
	int sign=1;
	cin>>n;
	cout<<"请输入插值点x:";
	cin>>x;
}

double result(double x, map<int, point> m)
{
	double mul=1, sum=0;
	for(int i=0;i<m.size();i++){
		mul=1;
		for(int j=0;j<m.size();j++){
			if (j==i) continue;
			mul*=((x-m[j].x)/(m[i].x-m[j].x));
		}
		sum+=(mul*m[i].y);
	}
	return sum;
}

void Start(int n){
	double a,b,x,d;
	int sign=1;
	for(auto &i:J){
		if (x<i.second.x) {
			break;
		}
		sign = i.first;
	}
	
	if(n%2==0){
		if(sign+n/2<=6)
			if(sign-n/2>=0){
				for(int i=0,j=0;i<n/2;j++){
					m[j]=J[sign-i];
					i++;
					m[++j]=J[sign+i];	
				}
			}				
			else for(int i=0;i<n;i++) m[i] = J[i];
			else{
				for(int i=0,j=6;i<n;i++)
					m[i]=J[j--];
			}
	}
	if (n%2!=0){
		if(sign+n/2<=6){
			if(sign-n/2>=0){
				for(int i=0,j=0;i<n/2;j++){
					m[j]=J[sign-i];
					i++;
					m[++j]=J[sign+i];
				}
			}
			else{
				for(int i=1; i<=n; i++){
					m[i]=J[i];
				} 						
			}			
		}
		else{
			for(int i=1, j=6; i<=n; i++){
				m[i]=J[j--];
			}							
		}
		if(sign-n/2+1<6) m[n/2+2]=J[sign+n/2+1];
		else m[n/2+2]=J[sign-n/2-1];
	}
}
