#include<iostream>  
using namespace std;  
int main()  
{  
    int i = 42;  
    cout<< "i :\t" << i <<endl;  
  
    int& r = i;  
    // &紧随类型名出现，因此是声明的一部分，r是一个引用  
    cout<< "r :\t" << r <<endl;  
  
    int* p;  
    // *紧随类型名出现，因此是声明的一部分，p是一个指针  
  
    p = &i;  
    // &出现在表达式中，是一个取地址符  
    cout<< "*p :\t" << *p <<endl;  
  
    *p = i;  
    // *出现在表达式中，是一个解引用符  
    cout<< "*p :\t" << *p <<endl;  
  
    int& r2 = *p;  
    // &是声明的一部分，*是一个解引用符  
    cout<< "r2 :\t" << r2 <<endl;  
  
    return 0;  
}  
