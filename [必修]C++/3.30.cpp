//T3.30
#include <iostream>
using namespace std;

class counter{
private:
	int value;
public:
	counter(int number);
	void increment();
	void decrement();
	int getvalue();
	int print();
};
counter::counter(int number){
	value=number;
}
void counter::decrement(){
	value--;
}
void counter::increment(){
	value++;
}
int counter::getvalue(){
	return value;	
}
int counter::print(){
	cout<<"The value is "<<value<<endl;
	return 0;
}

int main(){
	counter a(1);
	a.print();
	a.increment();
	a.print();
	a.decrement();
	cout<<"Test function 'getvalue' :"<<a.getvalue();
	
}
