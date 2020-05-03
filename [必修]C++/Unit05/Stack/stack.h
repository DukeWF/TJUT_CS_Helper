#ifndef STACK_H
#define STACK_H

class Stack
{
	public:
		Stack(int elements[100],int size);
		bool empty();
		int peek();
		int push(int value);
		int pop();
		int getSize();
	protected:
		int elements[100];
		int size;
};

#endif
