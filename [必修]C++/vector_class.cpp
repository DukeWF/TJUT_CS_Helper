#include <iostream>
using namespace std;
class vector{
	private:
		int dim;//ά��
		int *v; 
	public:
		vector(int t);
		vector(int t, int demmy);
		vector operator*(int k);
		vector operator+(vector &vec);
		vector operator-(vector &vec);
		void show();
};
//
vector vector::vector(int t){
	
}
void vector::show(){
	
} 
//
int main(){
	vector v1(3);
	v1.show();
	vector v2(3);
	v2.show();
	vector v3=v1+v2;//���ã�Ĭ�ϣ��������캯��
	v3.show();
	return 0; 
}
