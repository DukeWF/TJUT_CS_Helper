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
										cout<<"��"<<t<<"�ַ�ʽ��"<<endl; 
										cout<<"5��"<<i<<"��"<<' ';
										cout<<"2��"<<j<<"��"<<' ';
										cout<<"1��"<<k<<"��"<<endl;
									}
							}
					}
			}
		
	} 
