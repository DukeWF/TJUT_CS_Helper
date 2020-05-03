#include "stack.h"

Stack::Stack(int elements[],int size)
{
	this->size = size;
	for(int i = 0; i < size; i++)
	{
		this->elements[i]=elements[i];
	}
}
bool Stack::empty()
{
	return (size == 0);
}
int Stack::peek()
{
	return elements[size - 1];
}
int Stack::push(int value)
{
	return elements[size++] = value;
}
int Stack::pop()
{
	return elements[--size];
}
int Stack::getSize()
{
	return size;
}
