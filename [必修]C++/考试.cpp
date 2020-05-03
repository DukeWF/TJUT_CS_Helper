#include <iostream>
using namespace std;

class base{
	protected:
		int base_a;
		double base_b;
	public:
		base(){
			cout<<"a:";
			cin>>base_a;
			cout<<"b:";
			cin>>base_b;
		}
		base(int a, double b){
			base_a=a;
			base_b=b;
		}
		base(const base &b){
		}
		void change_int(int a){
			base_a=a;
		}
		void get_int(){
			return base_a;
		}
		void show_int(){
			cout<<"a:"<<base_a<<endl;
		}
		void change_double(){
			base_b=b;
		}
		void get_double(){
			return base_b;
		}
		void show_double(){
			cout<<"b:"<<base_b<<endl;
		}
};
class derive:public base{
	private:
		int derive_c;
	public:
		derive();
		derive():base(int a, double b),derive_c(c){
		}
		
};
