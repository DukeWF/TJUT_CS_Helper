#include <iostream>
using namespace std;

class student{
	private:
		int id;
		int scores[3];
	public:
		//decleration:类的声明 
//		void init(int sid, int a, int b, int c);
//		void show();
//		double average();
//		double gpa();
		//implementation：类的实现
		/*两种方法实现：
		  1.inside class：类的内部
		  2.outside ：类的外部 
		*/
		void init(int sid, int a, int b, int c)
			{
				id = sid;
				scores[0]=a;
				scores[1]=b;
				scores[2]=c;
			} 
		void show()
			{
				cout<<"student id is: "<<id<<endl<<"and the score of him & her is:"; 
				for(int i=0;i<3;i++)
					cout<<" "<<scores[i];
				cout<<endl;
			}
		double average()
			{
				int t=0;
				for(int i=0;i<3;i++)
					t+=scores[i];
				return t/3.0; 
			}
}; 
//双冒号表示属于类0 
//void student::init(int sid, int a, int b, int c)
//			{
//				id = sid;
//				scores[0]=a;
//				scores[1]=b;
//				scores[2]=c;
//			} 
int main()
	{
		student s1, s2;
		s1.init(1,99,98,100);
		s1.show();
		int a = s1.average();
		cout<<"the average score is: "<<a<<endl<<endl;
		s2.init(2,60,59,58);
		s2.show(); 
		int b = s2.average();
		cout<<"the average score is: "<<b<<endl;
		return 0;
	}
