#include <iostream>
using namespace std;
class complex{
	protected:
		double a, b;
	public:
		complex(double _a=0,double _b=0):a(_a),b(_b){
		}
		complex operator +(complex &t){
			return complex(a+t.a,b+t.b);
		}
		void show(){
			cout<<"The complex is:"<<a<<"+"<<b<<"i";
		}
};
int main(){
	complex a(1,2),b(3,4);
	complex z=a+b;
	z.show();
}
