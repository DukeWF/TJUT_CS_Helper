#include "StackOfIntegers.h"

StackOfIntegers::StackOfIntegers()
{
  size = 0;
}

bool StackOfIntegers::empty()
{
  return (size == 0);
}

int StackOfIntegers::peek()
{
    return elements[size - 1];
}

int StackOfIntegers::push(int value)
{
  //return elements[size++] = value;
  elements[size] = value;
  size++;
  return value;
}

int StackOfIntegers::pop()
{
// Following 3 lines is for debug usage  
  int t = elements[--size];
  elements[size] = -1;
  return t;  
//  return elements[--size];
}

int StackOfIntegers::getSize()
{
  return size;
}
