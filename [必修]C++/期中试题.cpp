#include <iostream>
using namespace std;
class time{
	private:
		int s,m,h;
	public:
		time(int _h=0,int _m=0,int _s=0):s(_s),m(_m),h(_h){
		}
		time operator++(int dummy){
			time t=*this;
			++s;
			if(s>=60){
				s%=60;
				++m;
				if(m>=60){
					m%=60;
					++h;
					if(h>=24){
						h%=24;
					}
				}			
			}
			return t;
		}
		time operator++(){
			++s;
			if(s>=60){
				s%=60;
				++m;
				if(m>=60){
					m%=60;
					++h;
					if(h>=24){
						h%=24;
					}
				}			
			}
			return *this;
		}		
		time operator+(time &t){
			time temp;
			temp.s=(s+t.s)%60;
			temp.m=(m+t.m+(s+t.s)/60)%60;
			temp.h=(h+t.h+(m+t.m)/60)%24;
			return temp; 
		}
		void show(){
			cout<<"当前时间："<<h<<":"<<m<<":"<<s<<endl;
		}
}; 
int main(){
	time a(2,30,59),b(4,20,33),c;
	a++;
	system("pause");
	a.show();
	++a;
	system("pause");
	a.show();
	c=a+b;
	c.show();
	
	return 0;
}
