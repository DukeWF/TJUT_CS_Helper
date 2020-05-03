#include <iostream>
using namespace std;
int main()
	{
		int t=0;
		int i, j, k;
		for(i=0;i<=20;i++)
			{
				for(j=0;j<=50;j++)
					{
						for(k=0;k<=100;k++)
							{
								if(5*i+2*j+k==100)
									{	
										t++;
										cout<<"第"<<t<<"种方式："<<endl; 
										cout<<"5分"<<i<<"个"<<' ';
										cout<<"2分"<<j<<"个"<<' ';
										cout<<"1分"<<k<<"个"<<endl;
									}
							}
					}
			}
		
	} 
