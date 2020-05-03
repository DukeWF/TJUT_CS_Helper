#include <iostream>
#include <map>
using namespace std;
typedef struct point{
	double x,y;
}point;
map<int,point>JL,MAP;
void init_map(){
	double a, b,x;
	for (int i = 1; i <=6; i++){
		cout<<"请 输入节点"<<i<<':';
		cin>>a>>b;
		JL.insert({ i,{a,b} });
	}
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
void Joseph_Louis(){
	init_map();
	cout<<"请 输入节点数量与插值点:";
	int n,sign=1;
	cin>>n>>x;
	for(auto &i:JL){
		if(x<i.second.x) break;
		sign=i.first;
	}
}

int main(){
	Joseph_Louis();
}
