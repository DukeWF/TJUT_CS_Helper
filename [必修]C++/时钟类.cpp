#include <iostream>
#include <stdio.h>
using namespace std;

class clock{
	private:
		int min, sec;
	public:
		//Constructor 
		clock(){
			cout<<"I am the first constructor"<<endl;
		}
		clock(int m, int s){
			cout<<"I am the second constructor"<<endl;
			min = m;
			sec = s;
		} 
		clock(const clock &c){
			cout<<"I am the third constructor"<<endl;
			min = c.min;
			sec = c.sec;
		}//��¡������ 
		//���캯�� 
		void set(int m, int s)
			{
				min=m;
				sec=s;
			}
		void tick()
			{
				sec++;
				if(sec==60)
					{
						sec=0;
						min++;
					}
			}
		void show()
			{
				cout<<min<<" min "<<sec<<" sec "<<endl;	
			}	
};
int main()
	{
//��һ�ε��ù��캯�� 
		clock t;
//�ڶ��ε��ù��캯��		
		clock s(1,58); 
		s.show();
		if(getchar()=='\n')
			s.tick();
		s.show();
//�����ε��ù��캯��		
		clock m(s);
		m.show();
		return 0;
	}
