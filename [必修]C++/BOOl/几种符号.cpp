#include<iostream>  
using namespace std;  
int main()  
{  
    int i = 42;  
    cout<< "i :\t" << i <<endl;  
  
    int& r = i;  
    // &�������������֣������������һ���֣�r��һ������  
    cout<< "r :\t" << r <<endl;  
  
    int* p;  
    // *�������������֣������������һ���֣�p��һ��ָ��  
  
    p = &i;  
    // &�����ڱ��ʽ�У���һ��ȡ��ַ��  
    cout<< "*p :\t" << *p <<endl;  
  
    *p = i;  
    // *�����ڱ��ʽ�У���һ�������÷�  
    cout<< "*p :\t" << *p <<endl;  
  
    int& r2 = *p;  
    // &��������һ���֣�*��һ�������÷�  
    cout<< "r2 :\t" << r2 <<endl;  
  
    return 0;  
}  
