#include <iostream>
using namespace std;
int fun(int &x,int &y)
	{
		if(x>y)
			{
			int t = x;
			x = y;
			y = t;
			}			
	}
double fun(double &x,double &y)
	{
		if(x>y)
			{
			double t = x;
			x = y;
			y = t;
			}			
	}
int main()
	{
		double a, b;
		cin>>a>>b;
		fun(a,b);
		cout<<a<<' '<<b;
		return 0;
	}	
