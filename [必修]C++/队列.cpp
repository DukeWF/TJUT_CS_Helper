#include<iostream>
using namespace std;
template <typename T>
class Queue{
	private:
		T *data;
		int size;
		int head;//头部位置 
		int tail;//尾部位置 
	public:
		Queue(int s){
			data = new T[s+1];
			size = s+1;
			head = 0;
			tail = 0;
		}
		~Queue(){
			delete []data;
		}
		void push(T d){
			if(!isFull()){
				data[tail] = d;
				tail = (tail + 1) % size;
				cout<<"Push Success!"<<endl;
			}
			else{
				cout<<"It is full!"<<endl;
				return;
			}
		}
		void pop(){
			if(!isEmpty()){
				data[head].~T();
				head = (head + 1) % size;
				cout<<"Pop Success!"<<endl;
			}else{
				cout<<"It is empty!"<<endl;
			}
		}
		bool isFull(){
			return (head == (tail+1) %size) ?1:0;
		}
		bool isEmpty(){
			return (head==tail)?1:0;
		}
		void show(){
			int i;
			for(i=head;tail!=i%size;(i+1)%size)
				cout<<data[i]<<endl;
		} 

};

int main(){
	int n,i;
	Queue<int> test(5);
	n=5;
	test.push(5);test.push(20);test.push(50);test.push(35);test.push(65);test.push(655);
	test.pop();
	cout<<endl;
	test.show();
//	test.pop();test.show();
}
