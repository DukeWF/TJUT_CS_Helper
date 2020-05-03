#include <iostream>
using namespace std;
const int size=10;
template <typename Type>
class Stack{
	public:
		void init(){
			tos=0;
		}
		void push(Type ch);
		Type pop();
	private:
		Type stck[size];
		int tos;//将要压入堆栈数据所在的下标 
};
template <typename Type>
void Stack<Type>::push(Type ob){
	if(tos==size){
		cout<<"Stack is FULL!";
		return;
	}
	stck[tos]=ob;
	tos++;
}
template <typename Type>
Type Stack<Type>::pop(){
	if(tos==0){
		cout<<"Stack is EMPTY!";
		return 0;
	}
	tos--;
	return stck[tos];
}
int main(){
	Stack <char>s;
	int i;
	s.init();
	s.push('A');
	s.push('B');
	s.push('C');
	for(i=0;i<3;i++){
		cout<<"POP s:"<<s.pop()<<endl;
	}
	Stack <int>is;
	is.push(1);
	is.push(2);
	is.push(3);
	for(i=0;i<3;i++){
		cout<<"POP is:"<<is.pop()<<endl; 
	}	
	return 0;
}

