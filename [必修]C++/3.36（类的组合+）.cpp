#include <iostream>
using namespace std;
class student{
	private:
		int ID;
		string name;
		double score;
	public:
		student(int id, string na, double sc){
			ID=id;
			name=na;
			score=sc;
		}
		double get_score(){
			return score;
		}
};
class Class{
	private:
		student std;
		int num=0;
		int all=0;
	public:
		Class(){
			std = new student;
			num++;
			all+=std->get_score();
		}
		int get_num(){
			return num;
		}
		double get_ave(){
			double ave=all/1.0*num;
			return ave; 
		}
		~Class(){
			delete std;
		}
};
//int main(){
//}
