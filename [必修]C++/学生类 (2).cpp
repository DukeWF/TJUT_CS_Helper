//Ñ§ÉúÀà 
#include <string>
#include <iostream>
using namespace std;
class std{
	private:
		int id;
		double score[];
				 			
	public:
		void set()
		{
			cout<<"input the id:";
			cin>>id;
			cout<<"input the score:";
			cin>>score[0]>>score[1]>>score[2];
		}
		void show()
		{
			cout<<"id"<<id<<endl
				<<"Chinese"<<score[0]<<endl
				<<"Maths"<<score[1]<<endl
				<<"English"<<score[2]<<endl;							
		}
		
};
